#pragma once
#include <iostream>
#include<string.h>
#include <windows.h>
#include "Koloda.h"
#include "Stol.h"
using namespace std;
class Player
{
private:
	//В основном не нужные
	string name;

	//Часто используемые
	vector<Karta>u_igroka;
	Karta star;//старшая карта
	float value;
	int komb = -1;
	string tip = "Nop";
	int stavka = 0;
	string sost;


	//Функции

	//Проверка комбинаций
	int prov_na_pari(vector<Karta>stol);
	void starsh();
	int prov_na_strit(Player t_player);
	int prov_na_royale(Player t_player);
	int prov_na_full_house(Player t_player);
	//Вспомогательные функции
	void sorti(vector<Karta>stol);

public:

	//Конструкторы
	Player(string _name, float _value) :name{ _name }, value{ _value }
	{
		sost = "Play";
	}
	Player(string _name, string _tip, float _value) :name{ _name }, tip{ _tip }, value{_value}{}

	//Гетеры
	string get_name();
	float get_value();
	int get_komb();
	string get_tip();
	string get_sost();
	Karta get_star();
	float get_stav();
	vector<Karta> get_hand();


	//Показывающие
	void text(int min_stav);
	void text_scrt();
	void fin_text();
	void temp_text();


	//Главные функции
	map<int, Karta> set_karti(map<int, Karta> koloda);

	void set_komb(vector<Karta>stol);


	//Сетеры
	void set_stav(int temp);
	void set_stav2(int temp);
	void set_tip(string _tip);
	void set_sost(string _sost);


	//Вспомогательные функции
	void plus_value(int plus);
};

