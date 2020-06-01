#include "workClass.h"


CRITICAL_SECTION section = { 0 }; //Ёто нужно, что бы созать ту самую секцию

VOID CriticalSec(VOID);


DWORD WINAPI CritSecFunc(LPVOID lpParam)
{


	for (DWORD i = 0; i < ITERATIONS; ++i)
	{
		EnterCriticalSection(&section);

		wcout << L" Thread " << *(DWORD*)lpParam << L" : " << i << L" This Thread have id= " << this_thread::get_id() << endl;
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
	HANDLE threads[COUNT_THREADS];


	InitializeCriticalSection(&section);
	for (DWORD i = 0; i < COUNT_THREADS; ++i)
	{
		DWORD *tmp = new DWORD;
		*tmp = i;
		threads[i] = CreateThread(NULL, 0, CritSecFunc, tmp, 0, 0);
	}

	WaitForMultipleObjects(COUNT_THREADS, threads, TRUE, INFINITE);
	DeleteCriticalSection(&section);

	for (size_t i = 0; i < COUNT_THREADS; ++i)
	{
		if (threads[i] != INVALID_HANDLE_VALUE)
			CloseHandle(threads[i]);
	}
}

int workClass::readwin()
{
	LPCSTR PATH = "D:/1/json.json";

	HANDLE hFile = CreateFile(PATH,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	OVERLAPPED olf = { 0 }; //—труктура, в которой задана позици€ в файле

	LARGE_INTEGER li = { 0 };

	li.QuadPart = 0;
	olf.Offset = li.LowPart;
	olf.OffsetHigh = li.HighPart;

	char* buffer = (CHAR*)calloc(SIZE_BUFFER + 1, sizeof(CHAR));
	DWORD iNumRead = 0;//ѕараметр, который получает кол-во считанных байт

	if (!ReadFile(hFile, buffer, SIZE_BUFFER, &iNumRead, &olf))
	return 1;
	if (olf.Internal == -1 && GetLastError())
	return 2;



	olf.Offset += iNumRead;//добавл€ем кол-во прочитанных байт

	cout << "====================================================" << endl;
	cout << "¬ы попали в чтение и вывод через winAPI " << endl;

	string b = string(buffer);
	cout << b << endl;




	CloseHandle(hFile);
	return 0;
}
