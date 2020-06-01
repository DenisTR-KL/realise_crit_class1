#pragma once
#include <windows.h>
//Для того, что бы считать файл
#include <iostream>
#include <string> // подключаем строки
#include <fstream>

#include <time.h>

#include <thread>
#include <chrono>


#include <windows.h>
#include <iostream>

#include <cstring>//Для того, что бы использовать strcpy

using namespace std;

#define COUNT_THREADS 5  //Константное количество потоков
#define ITERATIONS 101
#define SIZE_BUFFER 260

const int razm = 20;

class workClass
{
public:
	string nachinka[razm];

	void sin();

	void out();

	void krit();

	int readwin();
};

