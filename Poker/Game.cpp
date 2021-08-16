#include "Game.h"
#pragma warning(disable:4996)
//���� �������
void Game::set_players()
{
	string name;
	int count, temp;
	cout << "\n������� ���:\n";
	cin >> name;
	while (true)
	{

		cout << "\n���������� ��������� �����:\n";
		cin >> count;
		if (count < mb)
		{
			cout << "\n������� ���� �����!!!\n";
		}
		else
		{
			break;
		}
	}
	Player player(name, count);
	players.push_back(player);
	temp = players.size();
	koloda = players[temp - 1].set_karti(koloda);
	players[temp - 1].set_komb(stol.get_stol());
	players[temp - 1].set_tip("Player");

}

void Game::set_players(Player _player)
{
	players.push_back(_player);
	if (players[players.size() - 1].get_tip() == "Player")
	{
		kolvo_players++;
	}
	else
	{
		kolvo_botov++;
	}
}

void Game::set_bot()
{
	string name;
	int count, temp;
	temp = rand() % 10 + 1;
	switch (temp)
	{
	case 1:name = "Vitalik";
		break;
	case 2:name = "Margarita";
		break;
	case 3:name = "Vitoria";
		break;
	case 4:name = "Henry";
		break;
	case 5:name = "Jack";
		break;
	case 6:name = "Viola";
		break;
	case 7:name = "Pristanes";
		break;
	case 8:name = "Yarik";
		break;
	case 9:name = "Dad";
		break;
	case 10:name = "Kristopher";
		break;
	}
	temp = rand() % 10 + 1;
	count = temp * bb + (rand() % 10 * mb);
	Player player(name, count);
	players.push_back(player);
	temp = players.size();
	koloda = players[temp - 1].set_karti(koloda);
	players[temp - 1].set_komb(stol.get_stol());
	players[temp - 1].set_tip("Bot");
	temp = 0;
}

void Game::rand_rass()
{
	int temp_pl = 0, temp_bt = 0;
	if (kolvo_players == 0)
	{
		for (int i = 0; i < kolvo_botov; i++)
		{
			set_bot();
		}
	}
	else if (kolvo_botov == 0)
	{
		for (int i = 0; i < kolvo_players; i++)
		{
			set_players();
		}
	}
	else
	{
		for (int i = 0; i < kolvo_players + kolvo_botov; i++)
		{
			if (rand() % 2 == 0 && temp_pl != kolvo_players)
			{
				temp_pl++;
				set_players();
			}
			else if (temp_bt != kolvo_botov)
			{
				temp_bt++;
				set_bot();
			}
		}
	}
}


//��� ����
void Game::player_hod(int i, int kol_stol)//�� ����� ����� ��� ������ ���� � ����,������� ��� ��, ��� ����� �����
{
	system("cls");
	//������� ����� �����,���� ��� ����������(���������� kol_stol)
	if (kol_stol != 0)
	{
		cout << "\n����� �� �����: ";
		for (int o = 0; o < kol_stol; o++)
		{
			stol.text(o);
		}
	}
	//������� ����� i ������
	players[i].text(min_stav);
	int resh;
	while (true)
	{
		//����� ��������,���� ���� �����
		if (players[i].get_value() < min_stav)
		{
			cout << "� ������ " << i + 1 << " ������������ �����, �� �������� ����!!!\n...\n";
			players.erase(players.begin() + i);
			akt_player--;
			getchar();
			break;
		}
		//��� ���,��� �� �����:
		//Fold-�������� �����
		//Call-�������� ������
		//raise -�������
		//Check-����������(������ ���������� �����,���� ���� ������ ��������� �������)
		cout << "\n��� ��������?\n1-Fold        2-Call\n3-Raise        4-Check";
		cin >> resh;
		//���� ������� Fold
		if (resh == 1)
		{
			//�������,����� ��������,��� ����� ��������
			players[i].set_sost("Lose");
			akt_player--;
			break;
		}
		//���� ������� Call
		else if (resh == 2)
		{
			if (players[i].get_stav() != min_stav)
			{
				vse_stavki += min_stav - players[i].get_stav();
				players[i].set_stav(min_stav - players[i].get_stav());
			}
			break;

		}
		//���� ������� Raise
		else if (resh == 3)
		{
			while (true)
			{
				cout << "\n�� ������� ���������?(���������� �� "<<bb<<" )\n";
				cin >> resh;
				//���� ����� ������� �������� �����
				if (resh > players[i].get_value())
				{
					cout << "\n� ��� ������������ �������\n";
				}
				//���� ����� ������� ��������� ������(����������, �� ������� ����� �������� - 1 ��)
				else if (resh < bb)
				{
					cout << "\n������� ��������� ������\n";
				}
				//���� ��� ��������� �����
				else
				{
					min_stav = min_stav + resh;
					vse_stavki += min_stav - players[i].get_stav();
					players[i].set_stav(min_stav- players[i].get_stav());
					break;
				}
			}
			break;
		}
		//���� ������� Check
		else if (resh == 4)
		{
			if (players[i].get_stav() == min_stav)
			{
				break;
			}
			//���� ������ �� ��������� �������
			else
			{
				cout << "\n������!!!\n";
			}
		}
		//������ �� �������
		else
		{
			cout << "\n��������� �����,���������� ��� ���\n";
		}
	}
	Sleep(1500);
}

int Game::preflop()
{
	//�������,������� ������� �� ���������
	akt_player = players.size();

	//�� �������� � ��(����� ������(� ����� ������ 1 �����)) � ��(������� ������(2 �����)) � �������� ����� ������ ������ � �������� �������
	cout << "\n� ������� ������ ������ "<<mb;
	players[0].set_stav(mb);
	vse_stavki += mb;
	Sleep(1000);
	cout << "\n� ������� ������ ������ "<<bb;
	players[1].set_stav(bb);
	vse_stavki += bb;
	Sleep(100);
	//������ �������� ����������
	int resh, temp = 2, rand2;
	//��� ��� ����� ������� ������,���� ��� ��(�������� ����)
	min_stav = bb;

	//���� ��� ���� �� ��������,���� �� ��������� ������
	while (prov_stav())
	{

		//��� ��� ������ ����� �����,��������� �� ��

		//������ ��� ����� ���������� ���,���� ��� ��������� � ���������


		for (int i = 2; i < players.size(); i++)
		{
			if (players[i].get_sost() != "Lose")
			{
				cout << "\n����� ����� " << i + 1 << endl;
				Sleep(1500);
				if (players[i].get_tip() == "Player" )
				{
					player_hod(i, 0);
				}
				else if (players[i].get_tip() == "Bot" )
				{
					rand2 = rand() % 10 + 1;
					if (players[i].get_value() < min_stav)
					{
						cout << "� ������ " << i << " ������������ �����, �� �������� ����!!!\n...\n";
						players.erase(players.begin() + i);
						akt_player--;
						getchar();

					}
					else if (rand2 >= 3)//��� ������� "��� ��������",���� ���������� ������ 3,����� ��� ���������� �����
					{
						players[i].set_stav(min_stav - players[i].get_stav());
						vse_stavki += min_stav - players[i].get_stav();
					}
					else
					{
						players[i].set_sost("Lose");
						akt_player--;
					}
				}
			}
		}

		//������ � ����� ����� ��,����� ��


		for (int i = 0; i < 2; i++)
		{
			cout << "\n����� ����� " << i + 1 << endl;
			Sleep(2000);
			//��� ��
			if (i == 0)
			{
				if (players[i].get_tip() == "Player" && players[i].get_sost() != "Lose")
				{
					player_hod(i, 0);
				}
				else if (players[i].get_tip() == "Bot" && players[i].get_sost() != "Lose")
				{
					rand2 = rand() % 10 + 1;
					if (players[i].get_value() < min_stav)
					{
						cout << "� ������ " << i + 1 << " ������������ �����, �� �������� ����!!!\n...\n";
						players.erase(players.begin() + i);
						getchar();
						akt_player--;
					}
					else if (rand2 > 3)
					{
						players[i].set_stav(min_stav - players[i].get_stav());
						vse_stavki += min_stav - players[i].get_stav();
					}
					else
					{
						players[i].set_sost("Lose");
						akt_player--;
					}
				}
			}
			//��� ��
			else
			{
				if (players[i].get_tip() == "Player")
				{
					player_hod(i, 0);
				}
				else if (players[i].get_tip() == "Bot")
				{
					rand2 = rand() % 10 + 1;
					if (players[i].get_stav() != min_stav)
					{
						if (players[i].get_value() < min_stav)
						{
							cout << "� ������ " << i + 1 << " ������������ �����, �� �������� ����!!!\n...\n";
							players.erase(players.begin() + i);
							akt_player--;
						}
						else
						{
							players[i].set_stav(min_stav);
						}
					}
				}
			}
		}
	}

	//��� � �������,�� �����������,�� ��� ���� �� ���� �����
	return proverka_na_okonch();

}

int Game::round(int kol_stol)
{
	int resh, rand2;
	while (true)
	{

		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].get_sost() != "Lose")
			{
				cout << "\n����� ����� " << i + 1 << endl;
				Sleep(2000);
				if (players[i].get_tip() == "Player")
				{
					player_hod(i, kol_stol);
				}
				else if (players[i].get_tip() == "Bot")
				{
					rand2 = rand() % 10 + 1;
					if (players[i].get_value() < min_stav)
					{
						cout << "� ������ " << i << " ������������ �����, �� �������� ����!!!\n...\n";
						players.erase(players.begin() + i);
						akt_player--;
						getchar();
					}
					else if (rand2 <= 2 && players[i].get_komb() > 5 && players[i].get_value() >= 2 * min_stav)
					{
						players[i].set_stav(2 * min_stav - players[i].get_stav());
						vse_stavki +=2 * min_stav - players[i].get_stav();
					}
					else if (rand2 >= 3)//�� �� "��� ��������" 
					{
						players[i].set_stav(min_stav - players[i].get_stav());
						vse_stavki += min_stav - players[i].get_stav();
					}
					else if (players[i].get_komb() < 2 && rand2 < 3)
					{
						players[i].set_sost("Lose");
						akt_player--;
					}
				}
			}
			
		}

		if (!prov_stav())
		{
			break;
		}
	}
	return proverka_na_okonch();

}

void Game::rezult()
{
	pod_rez();
	cout << "\n� ���,���������,�����������!!!\n";
	for (int i = 0; i < players.size(); i++)
	{
		players[i].fin_text();
	}
	cout << "\n�� �����: \n";
	stol.text();
	cout << "\n����������� �������� ����� �� ����\n";
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].get_sost() == "Win")
		{
			players[i].plus_value(vse_stavki / t);
		}
	}
}

void Game::pod_rez()//�������  �����������
{
	int temp = proverka_na_okonch();
	if (temp != -1)
	{
		if (temp == players.size())
		{
			cout << "\n����������� ���!!!\n";
			for (int i = 0; i < players.size(); i++)
			{
				players[i].set_sost("Lose");
			}
		}
		else
		{
			for (int i = 0; i < players.size(); i++)
			{
				if(i!=temp)
				players[i].set_sost("Lose");
				else
				players[temp].set_sost("Win");
			}
		}
	}
	else
	{
		temp = 0;
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].get_komb() > max_komb)
			{
				max_komb = players[i].get_komb();
				kol_komb = 1;
				temp = i;
				max_starh = players[i].get_star().get_nom();
				t = 1;
			}
			else if (players[i].get_komb() == max_komb)
			{
				kol_komb++;
				if (players[i].get_star() > players[temp].get_star())
				{
					max_starh = players[i].get_star().get_nom();
				}
				else if (players[i].get_star().get_nom() == players[max_starh].get_star().get_nom())
				{
					t++;
				}
			}
		}
		for (int k = 0; k < players.size(); k++)
		{
			if (players[k].get_komb() == max_komb && players[k].get_star().get_nom() == max_starh)
			{
				players[k].set_sost("Win");
			}
			else
			{
				players[k].set_sost("Lose");
			}
		}
	}
	
}


//��������������� �������
int Game::proverka_na_okonch()
{
	if (akt_player == 0)
	{
		return players.size();
	}
	else if (akt_player < 2)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i].get_sost() != "Lose")
			{
				players[i].get_sost() = "Winner";
				return i;
			}
		}
	}
	else
	{
		return -1;
	}
}

bool Game::prov_stav()
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].get_sost() != "Lose" && players[i].get_stav() != min_stav)
		{
			return true;
		}
	}
	return false;
}

void Game::clear1()//������� �������� �� ����������� ��������� �������� � �����������, � ����� ����������� ����
{
	min_stav = bb;
	akt_player = 0;
	vse_stavki = 0;
	max_starh = 0;
	kol_komb = 0;
	max_komb = 0;
	t = 1;
	for (int i = 0; i < 5; i++)
	{
		koloda.insert(make_pair(koloda.size(), stol.get_stol()[i]));
	}
	stol.get_stol().clear();
	for (int i = 0; i < players.size(); i++)
	{
		players[i].set_stav2(0);
		for (int j = 0; j < 2; j++)
		{
			koloda.insert(make_pair(koloda.size(), players[i].get_hand()[j]));
		}
		players[i].get_hand().clear();
		players[i].set_sost("Play");
	}
}

void Game::before_raund()
{
	stol.set_carti(koloda);
	for (int i = 0; i < players.size(); i++)
	{
		players[i].set_karti(koloda);
		players[i].set_komb(stol.get_stol());
	}
}

int Game::save()
{
	ofstream savee("saveee.txt");
	savee << mb;
	savee << "\n";
	savee << bb;
	savee << "\n";
	for (int i = 0; i < players.size(); i++)
	{
		savee << players[i].get_tip();
		savee << "\n";
		savee << players[i].get_name();
		savee << "\n";
		savee << players[i].get_value();
		savee << "\n";
	}
	
	savee.close();
	return 0;
}

void Game::load()
{
	string t_name,t_tip;
	int t_mb, t_bb, t_value;
	ifstream savee("saveee.txt");
	
	if (savee.is_open())
	{
		savee >> t_mb >> t_bb;
		mb = t_mb;
		bb = t_bb;
		while (!savee.eof())
		{
			savee >> t_tip >> t_name >>t_value;
			if (t_value==0)
			{
				break;
			}
			Player t_player(t_name, t_tip, t_value);
			set_players(t_player);
			t_name.clear();
			t_tip.clear();
			t_value = 0;
		}
	}
	savee.close();
}


//������
vector<Player> Game::get_players()
{
	return players;
}

int Game::get_kolvo_players()
{
	return kolvo_players;
}

int Game::get_kolvo_botov()
{
	return kolvo_botov;
}

int Game::get_kolvo_ucastn()
{
	return kolvo_botov + kolvo_players;
}

Stol Game::get_stol()
{
	return stol;
}

map<int, Karta> Game::get_koloda()
{
	return koloda;
}



//���������
void Game::text_pl(int nomer)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (i != nomer)
		{
			players[i].text_scrt();
		}
		else
		{
			players[i].text(min_stav);
		}
	}
}
