#include <windows.h>
//��� ����, ��� �� ������� ����
#include <iostream>
#include <string> // ���������� ������
#include <fstream>

#include <time.h>

#include <thread>
#include <chrono>


#include <cstring>//��� ����, ��� �� ������������ strcpy
#include "workClass.h"

int main(int argc, char* args[])
{
	//CriticalSec();

	workClass first;
	int menu = 0;

	
	setlocale(LC_ALL, "Russian");
	

	cout << "��� ���������� ����� ��������� ����������. ���� � ���  �� ������ ������ d:\\1\\json.txt" << endl;
	cout << "�������� ������ ������  ����������(string) ���� � �������  JSON, �� ��� ������ �� ������� � ����������!" << endl;
	
	cout << "���� �� ������� ������ '1', �� ��� ������� ������ " << endl;
	cout << "���� �� ������� ������ '2', �� ��� ������� ��� ������ �� ����� ������� ��������, ����� ����  " << endl;
	cout << "���� �� ������� ������ '3', �� ��������� ������� 5 �������, ������� ����� ������������ ������, ����� ���� ������ ����� ����������" << endl;
	cout << "���� �� ������� ������ '4', ��  ������� �� winAPI ������ �������� ��� ������ �� ��������(������� ������� � ��������) � ������� �� � �������." << endl;
	cout << "���� �� ������� ������ '5', �� �� �������� ��� ����" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "������� �����" << endl;
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
