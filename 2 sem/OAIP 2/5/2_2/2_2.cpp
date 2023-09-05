#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

union TIME
{
	unsigned int hours;
	unsigned int minutes;
};

struct TRAINS
{
	string number;
	string station;
	string travel_days;
	struct DEPARTURE_TIME
	{
		unsigned int hours : 5;
		unsigned int minutes : 6;
	} departure_time = { 0,0 };
	struct ARRIVAL_TIME
	{
		unsigned int hours : 5;
		unsigned int minutes : 6;
	} arrival_time = { 0,0 };


	void input()
	{
		cin.ignore();
		cout << "Введите номер поезда" << endl;
		getline(cin, number);
		cout << "Введите пункт назначения" << endl;
		getline(cin, station);
		cout << "Введите дни следования" << endl;
		getline(cin, travel_days);
		TIME time{};
		cout << "Введите время отправления" << endl;
		cout << "Введите час" << endl;
		cin >> time.hours;
		if (time.hours < 25)
		{
			departure_time.hours = time.hours;
		}
		cout << "Введите минуты" << endl;
		cin >> time.minutes;
		if (time.minutes < 61)
		{
			departure_time.minutes = time.minutes;
		}
		cout << "Введите время прибытия" << endl;
		cout << "Введите час" << endl;
		cin >> time.hours;
		if (time.hours < 25)
		{
			arrival_time.hours = time.hours;
		}
		cout << "Введите минуты" << endl;
		cin >> time.minutes;
		if (time.minutes < 61)
		{
			arrival_time.minutes = time.minutes;
		}
	}

	void output()
	{
		cout << "Номер поезда: " << number << endl;
		cout << "Пункт назначения: " << station << endl;
		cout << "Дни следования: " << travel_days << endl;
		cout << "Время отправления: " << departure_time.hours << ":" << departure_time.minutes << endl;
		cout << "Время прибытия: " << arrival_time.hours << ":" << arrival_time.minutes << endl;
	}

	bool search(string station)
	{
		bool flag = false;

		if (this->station == station)
		{
			flag = true;
		}

		return flag;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TRAINS train[SIZE];
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить информацию о поезде" << endl;
		cout << "2 - Вывести информацию" << endl;
		cout << "3 - Поиск поезда по пункту назначения" << endl;
		cout << "4 - Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите номер пустой записки" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				train[number - 1].input();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Введите номер записки" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				train[number - 1].output();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 3:
		{
			cin.ignore();
			cout << "Введите пункт назначения: ";
			string station;
			getline(cin, station);
			bool flag = false;

			for (int i = 0; i < SIZE; i++)
			{
				if (train[i].search(station))
				{
					train[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "Поезд не найден!" << endl;
			}
			break;
		}
		}
	} while (choice != 4);
}