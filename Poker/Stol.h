#pragma once
#include <iostream>
#include<string.h>
#include <windows.h>
#include "Koloda.h"
#include <vector>
using namespace std;
class Stol
{

private:
	vector<Karta>na_stole;

public:
	//Конструкторы
	Stol(map<int, Karta> koloda)
	{
		set_carti(koloda);
	}
	Stol()
	{

	};


	//Достающие карты
	void set_carti(map<int, Karta> koloda);


	//Гетеры
	vector<Karta> get_stol();

	//Показывающие
	void text();
	void text(int i);
};
