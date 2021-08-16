#pragma once
#include"Game.h"
//В этот раз буду создавать пометки,ведь так удобнее


int raund(Stol &stol, Game &game,int &t)
{
	int resh;
	string resh3;
	if (t != 0)
	{
		game.before_raund();
	}
	cout << "\nНачало нового раунда!!!\nНе забывайте,в конце,при вводе q,игра заканчивается\n";
	//Показ,сколько игроков играет
	cout << "\nИгроки: ";
	for (int i = 0; i < game.get_players().size(); i++)
	{
		game.get_players()[i].text_scrt();
	}
	cout << "\nДля продолжения введите любой символ\n";
	cin >> resh3;
	system("cls");
	//Первый раунд  торгов - префлоп

	resh = game.preflop();
	if (resh != -1)
	{
		if (resh == game.get_players().size())
		{
			cout << "\nАктивных игроков не осталось...";
			return 0;
		}
		else
		{
			game.rezult();
			return 1;
		}
	}
	//Вывод первых 3 карт стола
	system("cls");
	cout << "\nТри карты стола: ";
	for (int i = 0; i < 3; i++)
	{
		stol.text(i);
	}
	cout << "\nДля продолжения введите любой символ\n";
	cin >> resh3;
	system("cls");
	//Второй раунд торгов - Флоп
	resh = game.round(3);
	if (resh != -1)
	{
		if (resh == game.get_players().size())
		{
			cout << "\nАктивных игроков не осталось...";
			return 0;
		}
		else
		{
			game.rezult();
			return 1;
		}
	}
	//Вывод 4 карт стола
	cout << "\nЧетыре карты стола: ";
	for (int i = 0; i < 4; i++)
	{
		stol.text(i);
	}
	cout << "\nДля продолжения введите любой символ\n";
	cin >> resh3;
	system("cls");
	//Третий раунд торгов - Тёрн
	resh = game.round(4);
	if (resh != -1)
	{
		if (resh == game.get_players().size())
		{
			cout << "\nАктивных игроков не осталось...";
			return 0;
		}
		else
		{
			game.rezult();
			return 1;
		}
	}
	cout << "\nДля продолжения введите любой символ\n";
	cin >> resh3;
	system("cls");
	//Вывод 5 карт стола
	cout << "\nПять карты стола: ";
	for (int i = 0; i < 5; i++)
	{
		stol.text(i);
	}
	//Последний раунд - риверс
	resh = game.round(5);
	if (resh != -1)
	{
		if (resh == game.get_players().size())
		{
			cout << "\nАктивных игроков не осталось...";
			return 0;
		}
		else
		{
			game.rezult();
			return 1;
		}
	}
	cout << "\nДля продолжения введите любой символ\n";
	cin >> resh3;
	system("cls");
	//Результаты партии
	game.rezult();
	return 0;
}



int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float resh, resh2;
	int mb, bb;
	int t = 0;//счетчик,для подсчет раундов
	string resh3;
	Koloda koloda;
	Stol stol(koloda.get_koloda());
	Game game(koloda,stol);
	cout << "\nХотите загрузить игру?(да или нет)\n";
	cin >> resh3;
	if (resh3 == "да")
	{
		cout << "\nНачало загрузки!!!\n";
		game.load();
		cout << "\nЗагрузка завершена!!!\n";
		t = 1;
	}
	else if (resh3 == "нет")
	{
		//Начало игры,создание игроков
		while (true)
		{
			cout << "\nСколько живых игроков играет?\n";
			cin >> resh;
			cout << "\nСколько ботов играет?\n";
			cin >> resh2;
			if (resh + resh2 < 2)
			{
				cout << "\nМало игроков!!!(минимум 2)";
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "\nВведите начальные ставки\nМалый блэйнд: ";
			cin >> mb;

			cout << "\nБольшой блэйнд: ";
			cin >> bb;

			if (mb >= bb)
			{
				cout << "\nМалый блейнд не может быть больше большого блэйнда!!!";
			}
			else if (mb > 100000 || bb > 100000)
			{
				cout << "\nВы ввели слишком большие числа!!!";
			}
			else
			{
				break;
			}
		}
		Game gamee(resh, resh2, koloda, stol, bb, mb);
		cout << "\nОтлично,начинаем игру!!!";
		Sleep(2000);
		system("cls");
		cout << "\nОбязательные ставки " << mb << "/" << bb;
		cout << "\nДля продолжения введите любой символ...\nЕсли в конце фразы'...'  это означает,что нужно ввести любой символ";
		cin >> resh3;
		
		game=gamee;
	}
	//сама игра
	while (game.get_kolvo_ucastn() >= 2)
	{
		raund(stol, game, t);
		game.clear1();
		cout << "\nДля продолжения введите любой символ(для выхода - q,для сохранения - s)\n";
		cin >> resh3;
		if (resh3 == "q")
		{
			cout << "\nИгра закончена!!!\n";
			cout << "\nБыло произведено раундов: " << t;
			break;
		}
		else if (resh3 == "s")
		{
			game.save();
			cout << "\nСохранение произошло успешно!!!";
			cout << "\nХотите выйти?(да или нет)\n";
			cin >> resh3;
			if (resh3 == "да")
			{
				cout << "\nИгра закончена!!!\n";
				cout << "\nБыло произведено раундов: " << t;
				break;
			}
		}
	}	
}






