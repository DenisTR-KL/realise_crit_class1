#pragma once
#include <windows.h>
//��� ����, ��� �� ������� ����
#include <iostream>
#include <string> // ���������� ������
#include <fstream>

#include <time.h>

#include <thread>
#include <chrono>


#include <windows.h>
#include <iostream>

#include <cstring>//��� ����, ��� �� ������������ strcpy

using namespace std;

#define COUNT_THREADS 5  //����������� ���������� �������
#define ITERATIONS 14
#define SIZE_BUFFER 260

const int razm = 20;

class workClass
{
public:
	string nachinka[razm];

	//DWORD WINAPI CritSecFunc(LPVOID lpParam);

	void sin();

	void out();

	void krit();

	int readwin();
};

