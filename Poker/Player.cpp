#include "Player.h"
//Сэтеры
void Player::set_stav(int temp)
{
    stavka = stavka+temp;
    value = value - temp;
}

void Player::set_stav2(int temp)
{
    stavka = temp;
}

void Player::set_tip(string _tip)
{
    tip = _tip;
}

void Player::set_sost(string _sost)
{
    sost = _sost;
}


//Гетеры
string Player::get_name()
{
    return name;
}

float Player::get_value()
{
    return value;
}

string Player::get_tip()
{
    return tip;
}

string Player::get_sost()
{
    return sost;
}

float Player::get_stav()
{
    return stavka;
}

vector<Karta> Player::get_hand()
{
    return u_igroka;
}

Karta Player::get_star()
{
    return star;
}

int Player::get_komb()
{
    return komb;
}


//Показывающие
void Player::text(int min_stav)
{
    cout << "\n_____________________________";
    cout << "\nИмя игрока:  " << name;
    cout << "\nСчет игрока:  " << value;
    cout << "\nКарты игрока:  \n";
    temp_text();
    cout << "\nСостояние: " << sost;
    cout << "\nСтавка: " << stavka;
    cout << "\nМинимальная ставка: " << min_stav;
    cout << "\n_____________________________";
}

void Player::text_scrt()
{
    cout << "\n_____________________________";
    cout << "\nИмя игрока:  " << name;
    cout << "\nСчет игрока:  " << value;
    cout << "\nКарты игрока:  \n";
    for (int i = 0; i < 2; i++)
    {
        cout << "?????" << "    ???????\n";
    }
    cout << "\nСтавка: " << stavka;
    cout << "\n_____________________________";
}

void Player::fin_text()
{
    cout << "\n_____________________________";
    cout << "\nИмя игрока:  " << name;
    cout << "\nСчет игрока:  " << value;
    cout << "\nКарты игрока:  \n";
    temp_text();
    cout << "\nСостояние: " << sost;
    cout << "\nСтавка: " << stavka;
    cout << "\nКомбинация: " << komb;
    cout << "\n_____________________________";
}

void Player::temp_text()
{
    for (int i = 0; i < 2; i++)
    {
        if (u_igroka.at(i).get_mast() == 1)
        {
            cout << "\nПики ";
        }
        else if (u_igroka.at(i).get_mast() == 2)
        {
            cout << "\nКрести ";
        }
        else if (u_igroka.at(i).get_mast() == 3)
        {
            cout << "\nБуби ";
        }
        else if (u_igroka.at(i).get_mast() == 4)
        {
            cout << "\nЧерви ";
        }
        else
        {
            cout << "\nОшибка в мастях!!!\n";
        }
        if (u_igroka.at(i).get_nom() >= 2 && u_igroka.at(i).get_nom() <= 10)
        {
            cout << u_igroka.at(i).get_nom();
        }
        else if (u_igroka.at(i).get_nom() == 11)
        {
            cout << " Валет";
        }
        else if (u_igroka.at(i).get_nom() == 12)
        {
            cout << " Дама";
        }
        else if (u_igroka.at(i).get_nom() == 13)
        {
            cout << " Король";
        }
        else if (u_igroka.at(i).get_nom() == 14)
        {
            cout << " Туз";
        }
    }
}


//Главные функции
void Player::set_komb(vector<Karta>stol)
{
    int t_value = 1;//одно значение у карт
    int t_mast = 1;//одна масть
    Player t_player("NO_NAME", 10000);
    t_player.u_igroka = u_igroka;
    t_player.sorti(stol);
    if (prov_na_royale(t_player) == 9)//проверка на флеш рояль
    {
        komb = 9;
    }
    else if (prov_na_strit(t_player) == 8)//проверка на стрит флэш
    {
        komb = 8;
    }
    else
    {
        for (int i = 0; i < 6; i++)//для дальнейших вычислений комбинаций,находим количество  повторений масти и ранга
        {
            if (t_player.u_igroka[i].get_nom() == t_player.u_igroka[i + 1].get_nom())
            {
                t_value++;
            }
            if (t_player.u_igroka[i].get_mast() == t_player.u_igroka[i + 1].get_mast())
            {
                t_mast++;
            }
        }
        if (t_value == 4)//проверка на карэ
        {
            komb = 7;
        }
        else if (prov_na_full_house(t_player) == 6)//проверка на фулл хауз
        {
            komb = 6;
        }
        else if (t_mast >= 5)//проверка на флеш
        {
            komb = 5;
        }
        else if (prov_na_strit(t_player) == 4)//проверка на стрит
        {
            komb = 4;
        }
        else if (t_value == 3)//проверка на тройку
        {
            komb = 3;
        }
        else if (prov_na_pari(stol) == 2)//проверка на 2 пары
        {
            komb = 2;
        }
        else if (t_value == 2)//проверка на пару
        {
            komb = 1;
        }
        else//если ничего не подошло
        {
            komb = 0;
        }
    }
}

map<int, Karta> Player::set_karti(map<int, Karta> _koloda)
{
    int temp = 0;
    for (int i = 0; i < 2; i++)
    {
        while (true)
        {
            temp = rand() % _koloda.size();
            if (_koloda.find(temp) != _koloda.end())
            {
                break;
            }
        }
        u_igroka.push_back(_koloda[temp]);
        map <int, Karta> ::iterator full_name;
        full_name = _koloda.find(temp);
        _koloda.erase(full_name);
    }
    starsh();
    return _koloda;
}


//Вспомогательные функции
void Player::plus_value(int plus)
{
    value = value + plus;
}

void Player::sorti(vector<Karta> stol)
{
    Karta temp;
    for (int i = 0; i < stol.size(); i++)
        u_igroka.push_back(stol[i]);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i; j++)
        {
            if (u_igroka[j].get_nom() > u_igroka[j + 1].get_nom())
            {
                temp = u_igroka[j];
                u_igroka[j] = u_igroka[j + 1];
                u_igroka[j + 1] = temp;
            }
        }
    }
}


//проверка на комбинации
int Player::prov_na_pari(vector<Karta>stol)
{
    int temp = 0;
    int t_nom = 0;
    if (u_igroka.at(0).get_nom() == u_igroka.at(1).get_nom())
    {
        temp++;
        t_nom = u_igroka.at(0).get_nom();
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (u_igroka[i].get_nom() == stol[j].get_nom())
            {
                if (u_igroka.at(i).get_nom() != t_nom)
                    temp++;
            }
        }
    }
    if (temp >= 2)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

void Player::starsh()
{
    if (u_igroka.at(0) > u_igroka.at(1))
    {
        star = u_igroka.at(0);
    }
    else
    {
        star = u_igroka.at(1);
    }
}

int Player::prov_na_strit(Player t_player)
{
    int temp = 0;
    int temp2 = 0;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (t_player.u_igroka[i + j].get_nom() == t_player.u_igroka[i + j + 1].get_nom())
            {
                if (t_player.u_igroka[i + j].get_mast() == t_player.u_igroka[i + j + 1].get_mast())
                {
                    temp2++;
                }
                temp++;
            }
        }
        if (temp2 == 5)//проверка на стрит флэш
        {
            return 8;
        }
        else if (temp == 5)//прроверка на стрит
        {
            return 4;
        }
        temp = 0;
        temp2 = 0;
    }
    return -1;//если ничего нет
}

int Player::prov_na_royale(Player t_player)
{
    int temp = 0;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (t_player.u_igroka[i + j].get_nom() + 1 == t_player.u_igroka[i + j + 1].get_nom())
            {
                if (t_player.u_igroka[i + j].get_mast() == t_player.u_igroka[i + j + 1].get_mast())
                {
                    temp++;
                }
            }
        }
        if (temp == 5)//прроверка на флеш рояль
        {
            return 9;
        }
    }
    return -1;//если ничего нет
}

int Player::prov_na_full_house(Player t_player)
{
    int temp = 0, temp2 = 0, t_nom;
    for (int i = 0; i <= 4; i++)
    {
        if (t_player.u_igroka[i].get_nom() == t_player.u_igroka[i + 1].get_nom() && t_player.u_igroka[i + 1].get_nom() == t_player.u_igroka[i + 2].get_nom())
        {
            temp++;
            t_nom = t_player.u_igroka[i].get_nom();
            break;
        }
    }
    if (temp != 0)
    {
        for (int i = 0; i <= 5; i++)
        {
            if (t_player.u_igroka[i].get_nom() == t_player.u_igroka[i + 1].get_nom() && t_player.u_igroka[i].get_nom() != t_nom)
            {
                return 6;
            }
        }
    }
    return -1;
}

