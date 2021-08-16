#pragma once
#include "Karta.h"
#include <map>
class Koloda
{
private:
	map<int, Karta> koloda;
public:
	//Конструктор
	Koloda()
	{
		int temp = 1;
		for (int i = 1; i <= 4; i++)
		{
			for (int y = 2; y <= 14; y++)
			{
				Karta karta(i, y);
				koloda.insert(make_pair(temp, karta));
				temp++;
			}
		}
	}

	//Гетеры,на всякий случай
	map<int, Karta> get_koloda()
	{
		return koloda;
	}
};

