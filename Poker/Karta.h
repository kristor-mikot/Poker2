#pragma once
#include <string>
using namespace std;
class Karta
{
private:
	//Составляющие карты
	int mast;
	int nom;
public:
	//Конструкторы
	Karta()
	{
		mast = rand() % 3 + 1;
		nom = rand() % 12 + 2;
	}
	Karta(int _mast, int _nom)
	{
		mast = _mast;
		nom = _nom;
	}

	//Гетеры
	int get_mast();
	int get_nom();

	//Функции для моего удобства
	friend bool operator>(const Karta karta1, const Karta karta2)
	{
		if (karta1.nom > karta2.nom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

