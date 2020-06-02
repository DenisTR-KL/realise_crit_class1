#include "workClass.h"


CRITICAL_SECTION section = { 0 }; //Это нужно, что бы созать ту самую секцию, в глобальной области видемости структуры
                                 // и константы, этонормально


VOID CriticalSec(VOID);


DWORD WINAPI CritSecFunc(LPVOID lpParam)//LPVOID lpParam примемает id
{
	workClass a;
	ifstream fin;
	fin.open("d:\\1\\json.json");
	
	string str;
	for (DWORD i = 0; i < ITERATIONS; ++i)
	{
		EnterCriticalSection(&section);//Когда мы доходим до сюда, то секция блокируется для ВСЕХ других потоков

		if (!fin.is_open())
		{
			cout << "Error" << endl;
		}
		else
		{		
			fin >> str;	
		}
		//WCHAR e = str;

		cout << " Thread " << *(DWORD*)lpParam << " : " << i <<  " ||This Thread cout= "<< str << " ||This Thread have id= " << this_thread::get_id()<< endl;
		LeaveCriticalSection(&section);
		Sleep(rand() % 16 + 10);
	}

	ExitThread(0);
}

/*
DWORD __stdcall workClass::CritSecFunc(LPVOID lpParam)
{
	return 0;
}*/

void workClass::sin()
{
	//CriticalSec();
	ifstream fin;
	fin.open("d:\\1\\json.json");

	
	string buf[razm];

	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "File is open" << endl;

		string str;

		int j = 0;

		while (!fin.eof()) { // пока не достигнут конец файла класть очередную строку в переменную (str)

			fin >> str;

			if (str.size() > 0)
			{
				str.pop_back();
			}
			buf[j] = string(str);

			if (j > 1)
			{
				nachinka[j - 2] = buf[j];
			}
			j++;
		}
	}
	fin.close();
}

void workClass::out()
{
	cout << "=========================================" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (nachinka[i].length() > 1)
		{
			cout << "i = " << nachinka[i] << endl;
		}

	}
}

void workClass::krit()
{
	HANDLE threads[COUNT_THREADS];//создаём массив потоков на 5 переменных


	InitializeCriticalSection(&section); //инециализирует критическую секцию
	for (DWORD i = 0; i < COUNT_THREADS; ++i)//DWORD 32-битное беззнаковое целое. Аналоги: unsigned long int, UINT
	{
		DWORD *tmp = new DWORD;// создание переменной, чтобы мы могли её корректно передать
		*tmp = i;//если мы попробуем её прямо передать, то везде будет выводиться последнее значение цикла

		threads[i] = CreateThread(NULL, 0, CritSecFunc, tmp, 0, 0);
	}

	WaitForMultipleObjects(COUNT_THREADS, threads, TRUE, INFINITE);
	DeleteCriticalSection(&section);//Удаляет критическую секцию

	for (size_t i = 0; i < COUNT_THREADS; ++i)
	{
		if (threads[i] != INVALID_HANDLE_VALUE)
			CloseHandle(threads[i]); //закрывает дискриптор открытого объекта
	}
}

int workClass::readwin()
{


	cout << "====================================================" << endl;
	cout << "Вы попали в чтение и вывод через winAPI и потоков " << endl;
	LPCSTR PATH = "D:/1/json.json";

	HANDLE hFile = CreateFile(PATH,
		GENERIC_READ | GENERIC_WRITE,//читаем и пишем
		FILE_SHARE_READ,      
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	OVERLAPPED olf = { 0 }; //Структура, в которой задана позиция в файле

	
	LARGE_INTEGER li = { 0 };// Это структура, она состоит из DWORD и LONG (старший и младший разряд)

	li.QuadPart = 0;// Чтение с 0 символа
	olf.Offset = li.LowPart;
	olf.OffsetHigh = li.HighPart;

	char* buffer = (CHAR*)calloc(SIZE_BUFFER + 1, sizeof(CHAR));//Буфер в кодировке аски

	DWORD iNumRead = 0;//Параметр, который получает кол-во считанных байт

	if (!ReadFile(hFile, buffer, SIZE_BUFFER, &iNumRead, &olf))
	return 1;//Проверка , если вернёт НЕ 0, то всё хорошо
	if (olf.Internal == -1 && GetLastError())
	return 2;//Редкая ошибка



	olf.Offset += iNumRead;//добавляем кол-во прочитанных байт к текущей позиции


	string b = string(buffer);
	cout << b << endl;




	CloseHandle(hFile);//закрывает дискриптор открытого объекта
	return 0;
}
