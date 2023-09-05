#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 5

using namespace std;

enum SEX
{
	man = 1, woman
};

struct CITIZENS
{
	string FIO;
	struct BIRTH_DATE
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	} date = { 0,0,0 };
	string address;
	string sex;

	void input()
	{
		cin.ignore();
		cout << "Введите ФИО" << endl;
		getline(cin, FIO);
		cout << "Введите дату рождения (00 00 0000)" << endl;
		unsigned int day = 0, month = 0, year = 0;
		cin >> day >> month >> year;
		if (day < 32 && month < 13 && year < 2049)
		{
			date.day = day;
			date.month = month;
			date.year = year;
		}
		cin.ignore();
		cout << "Введите адрес" << endl;
		getline(cin, address);
		cin.ignore();
		cout << "Введите пол (1 - мужской, 2 - женский)" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case SEX::man:
		{
			sex = "Мужской";
			break;
		}
		case SEX::woman:
		{
			sex = "Женский";
			break;
		}
		default:
		{
			cout << "Неверный вариант" << endl;
			break;
		}
		}
	}

	void output()
	{
		cout << "ФИО: " << FIO << endl;
		cout << "Дата рождения:" << date.day << " " << date.month << " " << date.year << endl;
		cout << "Адрес: " << address << endl;
		cout << "Пол: " << sex << endl;
	}

	void del_citizen()
	{
		FIO = "";
		date = { 0,0,0 };
		address = "";
		sex = "";
	}

	bool search(unsigned int year)
	{
		bool flag = false;

		if (this->date.year == year)
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

	CITIZENS citizen[SIZE];
	int choice;
	do
	{
		cout << "Выберите вариант: " << endl;
		cout << "1 - Добавить горожанина" << endl;
		cout << "2 - Вывести информацию о горожанине" << endl;
		cout << "3 - Удалить информацию о горожанине" << endl;
		cout << "4 - Поиск горожанина по году рождения" << endl;
		cout << "5 - Выход" << endl;

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
				citizen[number - 1].input();
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
				citizen[number - 1].output();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Введите номер записки" << endl;
			int number;
			cin >> number;
			if (number <= SIZE)
			{
				citizen[number - 1].del_citizen();
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите год рождения: ";
			int day1, month1, year1;
			cin >> day1 >> month1 >> year1;
			bool flag = false;
			cin.ignore();

			for (int i = 0; i < SIZE; i++)
			{
				if (citizen[i].date.day == day1 && citizen[i].date.month == month1 && citizen[i].date.year == year1)
				{
					citizen[i].output();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "Горожанин не найден!" << endl;
			}
			break;
		}
		}
	} while (choice != 5);
}