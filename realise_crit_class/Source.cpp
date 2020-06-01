#include <windows.h>
//Для того, что бы считать файл
#include <iostream>
#include <string> // подключаем строки
#include <fstream>

#include <time.h>

#include <thread>
#include <chrono>


#include <cstring>//Для того, что бы использовать strcpy
#include "workClass.h"

int main(int argc, char* args[])
{
	//CriticalSec();

	workClass first;
	int menu = 0;

	
	setlocale(LC_ALL, "Russian");
	

	cout << "Это приложение имеет следующий функционал. Если у вас  по такому адресу d:\\1\\json.txt" << endl;
	cout << "хранится массив данных  строкового(string) типа в формате  JSON, то оно сможет их считать и обработать!" << endl;
	
	cout << "Если вы нажмете кнопку '1', то оно считает данные " << endl;
	cout << "Если вы нажмете кнопку '2', то оно выведет вам данные на экран обычным способом, после чего  " << endl;
	cout << "Если вы нажмете кнопку '3', то программа создаст 5 потоков, которые будут симулировать работу, после чего патоки будут уничтожены" << endl;
	cout << "Если вы нажмете кнопку '4', то  функция на winAPI читает полность все данные из блокнота(включая пробелы и переносы) и выводит их в консоль." << endl;
	cout << "Если вы нажмете кнопку '5', то Вы покините это меню" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Введите цифру" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:first.sin();
			break;
		case 2:first.out();
			break;
		case 3:first.krit();
			break;
		case 4: first.readwin();
			break;
		case 5:i+=10;
			break;
		default:
			break;
		}
		menu = 0;
	}




	system("pause");
	return 0;
}
