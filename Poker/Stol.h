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
	//������������
	Stol(map<int, Karta> koloda)
	{
		set_carti(koloda);
	}
	Stol()
	{

	};


	//��������� �����
	void set_carti(map<int, Karta> koloda);


	//������
	vector<Karta> get_stol();

	//������������
	void text();
	void text(int i);
};
