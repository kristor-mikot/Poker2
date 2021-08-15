#pragma once
#include "Karta.h"
#include "Koloda.h"
#include "Player.h"
#include "Stol.h"
#include<stdio.h>
#include <fstream>
#include<iostream>
#include<string.h>
#include <Windows.h>

class Game
{
private:
	//����������

	//�������
	vector<Player> players;
	Stol stol;
	map<int, Karta> koloda;
	int vse_stavki = 0;


	//���������������
	int kolvo_players = 0;
	int kolvo_botov = 0;
	int akt_player = 0;
	int min_stav = 2000;


	//����������� ����������
	int max_komb = 0;
	int kol_komb = 0;
	int max_starh = 0;
	int bb = 0;
	int mb = 0;

	//������ ����������� ����������
	int t = 1;


	//�������

	//����������� �������
	void player_hod(int i, int kol_stol);
	bool prov_stav();

	//������ �������
	void set_players();
	void set_players(Player _player);
	void set_bot();
	void rand_rass();


public:
	//�����������
	Game(int _kolvo_players, int _kolvo_botov, Koloda _koloda, Stol _stol, int _bb, int _mb) :kolvo_players{ _kolvo_players }, kolvo_botov{ _kolvo_botov }, bb{ _bb }, mb{_mb}
	{
		srand(time(0));
		koloda = _koloda.get_koloda();
		stol = _stol;
		rand_rass();
	}

	Game(Koloda _koloda, Stol _stol)
	{
		srand(time(0));
		koloda = _koloda.get_koloda();
		stol = _stol;
	}
	//������
	vector<Player> get_players();
	int get_kolvo_players();
	int get_kolvo_botov();
	int get_kolvo_ucastn();
	Stol get_stol();
	map<int, Karta> get_koloda();


	//��� ����
	int preflop();//������� �������� ������ �� 2 �����
	int round(int kol_stol);
	void rezult();
	void pod_rez();


	//���������
	void text_pl(int nomer);


	//���������������
	int proverka_na_okonch();
	void clear1();
	void before_raund();
	int save();
	void load();
};

