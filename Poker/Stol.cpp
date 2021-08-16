#include "Stol.h"
//Достающие карты
void Stol::set_carti(map<int, Karta> koloda)
{
    int temp = 0;
    for (int i = 0; i < 5; i++)
    {
        temp = rand() % koloda.size();
        na_stole.push_back(koloda[temp]);
        map <int, Karta> ::iterator full_name;
        full_name = koloda.find(temp);
        koloda.erase(full_name);
    }
}


//Гетеры
vector<Karta> Stol::get_stol()
{
    return na_stole;
}


//Показывающие
void Stol::text()
{
    for (int i = 0; i < 5; i++)
    {
        if (na_stole.at(i).get_mast() == 1)
        {
            cout << "\nПики ";
        }
        else if (na_stole.at(i).get_mast() == 2)
        {
            cout << "\nКрести ";
        }
        else if (na_stole.at(i).get_mast() == 3)
        {
            cout << "\nБуби ";
        }
        else if (na_stole.at(i).get_mast() == 4)
        {
            cout << "\nЧерви ";
        }
        else
        {
            cout << "\nОшибка в мастях!!!\n";
        }
        if (na_stole.at(i).get_nom() >= 2 && na_stole.at(i).get_nom() <= 10)
        {
            cout << na_stole.at(i).get_nom();
        }
        else if (na_stole.at(i).get_nom() == 11)
        {
            cout << " Валет";
        }
        else if (na_stole.at(i).get_nom() == 12)
        {
            cout << " Дама";
        }
        else if (na_stole.at(i).get_nom() == 13)
        {
            cout << " Король";
        }
        else if (na_stole.at(i).get_nom() == 14)
        {
            cout << " Туз";
        }
    }
}

void Stol::text(int i)
{
    if (na_stole.at(i).get_mast() == 1)
    {
        cout << "\nПики ";
    }
    else if (na_stole.at(i).get_mast() == 2)
    {
        cout << "\nКрести ";
    }
    else if (na_stole.at(i).get_mast() == 3)
    {
        cout << "\nБуби ";
    }
    else if (na_stole.at(i).get_mast() == 4)
    {
        cout << "\nЧерви ";
    }
    else
    {
        cout << "\nОшибка в мастях!!!\n";
    }
    if (na_stole.at(i).get_nom() >= 2 && na_stole.at(i).get_nom() <= 10)
    {
        cout << na_stole.at(i).get_nom();
    }
    else if (na_stole.at(i).get_nom() == 11)
    {
        cout << " Валет";
    }
    else if (na_stole.at(i).get_nom() == 12)
    {
        cout << " Дама";
    }
    else if (na_stole.at(i).get_nom() == 13)
    {
        cout << " Король";
    }
    else if (na_stole.at(i).get_nom() == 14)
    {
        cout << " Туз";
    }
}
