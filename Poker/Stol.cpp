#include "Stol.h"
//��������� �����
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


//������
vector<Karta> Stol::get_stol()
{
    return na_stole;
}


//������������
void Stol::text()
{
    for (int i = 0; i < 5; i++)
    {
        if (na_stole.at(i).get_mast() == 1)
        {
            cout << "\n���� ";
        }
        else if (na_stole.at(i).get_mast() == 2)
        {
            cout << "\n������ ";
        }
        else if (na_stole.at(i).get_mast() == 3)
        {
            cout << "\n���� ";
        }
        else if (na_stole.at(i).get_mast() == 4)
        {
            cout << "\n����� ";
        }
        else
        {
            cout << "\n������ � ������!!!\n";
        }
        if (na_stole.at(i).get_nom() >= 2 && na_stole.at(i).get_nom() <= 10)
        {
            cout << na_stole.at(i).get_nom();
        }
        else if (na_stole.at(i).get_nom() == 11)
        {
            cout << " �����";
        }
        else if (na_stole.at(i).get_nom() == 12)
        {
            cout << " ����";
        }
        else if (na_stole.at(i).get_nom() == 13)
        {
            cout << " ������";
        }
        else if (na_stole.at(i).get_nom() == 14)
        {
            cout << " ���";
        }
    }
}

void Stol::text(int i)
{
    if (na_stole.at(i).get_mast() == 1)
    {
        cout << "\n���� ";
    }
    else if (na_stole.at(i).get_mast() == 2)
    {
        cout << "\n������ ";
    }
    else if (na_stole.at(i).get_mast() == 3)
    {
        cout << "\n���� ";
    }
    else if (na_stole.at(i).get_mast() == 4)
    {
        cout << "\n����� ";
    }
    else
    {
        cout << "\n������ � ������!!!\n";
    }
    if (na_stole.at(i).get_nom() >= 2 && na_stole.at(i).get_nom() <= 10)
    {
        cout << na_stole.at(i).get_nom();
    }
    else if (na_stole.at(i).get_nom() == 11)
    {
        cout << " �����";
    }
    else if (na_stole.at(i).get_nom() == 12)
    {
        cout << " ����";
    }
    else if (na_stole.at(i).get_nom() == 13)
    {
        cout << " ������";
    }
    else if (na_stole.at(i).get_nom() == 14)
    {
        cout << " ���";
    }
}
