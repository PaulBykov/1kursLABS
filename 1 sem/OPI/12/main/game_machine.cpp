#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <io.h>
#include <fcntl.h>

using namespace  std;

extern float chance;
extern float balance;
extern float bet;

inline int f1(int n, int psize_cimbol)
{
	if (n == psize_cimbol)
		return (n -= psize_cimbol);
	return n;

}
inline int f2(int n, int psize_column, int psize_cimbol)
{
		if (n - psize_column < 0)
			return (n = psize_cimbol - psize_column + n + 1);
		else
			return ( n -= psize_column - 1);
}
inline int f3(int pr, int psize_column, int psize_cimbol)
{
	pr -= (psize_column - 1) / 2;
	if (pr < 0)
		pr += psize_cimbol;
	return(pr);
}

inline void mashine()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
	wchar_t B[] = { L'A', L'$', L'€', L'@', L'Ψ', L'☺', L'7', L'♥', L'♠', L'\0' };
	int r, m, p1 = 1, p2 = 1, p3 = 1, chance_rand, size_column = 5, r1, r2, r3, size_cimbol = sizeof(B) / 2 - 1, stop = 200;
	srand((unsigned)time(NULL));
	r1 = rand() % size_cimbol;
	r2 = rand() % size_cimbol;
	r3 = rand() % size_cimbol;
	chance_rand = rand() % 10000 + 1;
	if(chance_rand <= chance)
	{
		r = rand() % 9 - 4;
		r1 = 1 + r;
		r2 = 3 + r;
		r3 = 5 + r;
	}
	for (int j = 0; j < size_column; j++)
	{
		wcout << L"  " << B[j];
		wcout << L"  " << B[j];
		wcout << L"  " << B[j];
		wcout << endl;
	}
	for (int j = 0; j < size_column; j++)
	{
		wcout << "\x1b[A";
	}
	for (int i = 1; i < 350; i++)
	{

		if (i == 150)
		{
			p1 = f3(r1, size_column, size_cimbol);
			p2 = f3(r2, size_column, size_cimbol);
			p3 = f3(r3, size_column, size_cimbol);
		}
		for(int j = 0; j < size_column; j++)
		{
			p1 = f1(p1, size_cimbol);
			p2 = f1(p2, size_cimbol);
			p3 = f1(p3, size_cimbol);
			if (i > 30 && i < (stop + 6 * size_cimbol + 4))
				wcout << L"  " << B[p1++];
			if (i > (30 + 2 * size_cimbol + 5) && i < (stop + 3 * size_cimbol + 2))
				wcout << L"  " << B[p2++];
			if (i > (30 + 4 * size_cimbol + 11) && i < stop)
				wcout << L"  " << B[p3++];
			if(i > 30 && i < (stop + 6 * size_cimbol + 4))
				wcout << endl;
		}
		if (i > 30 && i < (stop + 6 * size_cimbol + 4))
		{
			p1 = f2(p1, size_column, size_cimbol);
		}
		if (i > (30 + 2 * size_cimbol + 5) && i < (stop + 3 * size_cimbol + 2))
		{
			p2 = f2(p2, size_column, size_cimbol);
		}
		if (i > (30 + 4 * size_cimbol + 11) && i < stop)
		{
			p3 = f2(p3, size_column, size_cimbol);
		}
		if(i > 30 && i < (stop + 6 * size_cimbol + 4))
		for (int j = 0; j < size_column; j++)
		{
			wcout << "\x1b[A";
		}
		Sleep(30);
	}
	for (int j = 0; j < size_column; j++)
	{
		wcout << endl;
	}
	if (p1 == p2 && p3 == p2)
	{
		if (p1 == 5)
		{
			wcout << L"Вы выграли!!!\nТри семерки. Отлично!!!";
			m = 7;
		}
		if (p1 == 2)
		{
			wcout << L"ПОЗДРАВЛЯЮ!!!\nУ вас выпало КОРОНА!!!(вирус)"; // осуждаю
			m = 10;
		}
		if (p1 == 1 || p1 == 0)
		{
			wcout << L"Вы выиграли!!!\n";
			m = 3;
		}
		if (p1 == 3 || p1 == 7)
		{
			wcout << L"Вы выиграли!!!\n";
			m = 5;
		}
		if (p1 == 8 || p1 == 6 || p1 == 4)
		{
			wcout << L"Вы выиграли!!!\n";
			m = 2;
		}
		wcout << L"Вы получаете " << balance * m;
		balance += bet * m;
		Sleep(1);
	}

	else
	{
		wcout << L"Вы проиграли " << bet << endl;
		balance -= bet;
		Sleep(1);
	}
}