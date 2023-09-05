#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>

using namespace std;

struct sanatorium
{
	string name;
	string location;
	string health_profile;
	int vouchers;

	void find_name(string search_name) {
		if (this->name == search_name) {
			list_output();
		}

	}
	void find_profile(string search_profile) {
		if (this->health_profile == search_profile) {
			list_output();
		}

	}
	void list_output() {
		cout << "Название санатория: " << name << "  " << endl;
		cout << "Расположение санатория: " << location << "  " << endl;
		cout << "Лечебный профиль: " << health_profile << "  " << endl;
		cout << "Количество путёвок: " << vouchers << "  " << endl;
		cout << endl;
	}
};

void table_head() {
	cout << left << setw(20) << "Лечебный профиль" << left << setw(20) << "Название санатория" << left
		<< setw(20) << "Расположение" << left << setw(20) << "Количество путёвок" << endl << endl;
}

void output(sanatorium arr[]) {
	table_head();
	cout << left << setw(20) << arr[0].health_profile
		<< left << setw(20) << arr[0].name
		<< left << setw(20) << arr[0].location
		<< left << setw(20) << arr[0].vouchers
		<< "\n\n\n\n";
	cout << left << setw(20) << arr[2].health_profile
		<< left << setw(20) << arr[2].name
		<< left << setw(20) << arr[2].location
		<< left << setw(20) << arr[2].vouchers
		<< "\n\n\n\n";
	table_head();
	cout << left << setw(20) << arr[1].health_profile
		<< left << setw(20) << arr[1].name
		<< left << setw(20) << arr[1].location
		<< left << setw(20) << arr[1].vouchers
		<< "\n\n\n\n";
	table_head();
	cout << left << setw(20) << arr[4].health_profile
		<< left << setw(20) << arr[4].name
		<< left << setw(20) << arr[4].location
		<< left << setw(20) << arr[4].vouchers
		<< "\n\n\n\n";
	table_head();
	cout << left << setw(20) << arr[3].health_profile
		<< left << setw(20) << arr[3].name
		<< left << setw(20) << arr[3].location
		<< left << setw(20) << arr[3].vouchers
		<< "\n\n\n\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	sanatorium objects[5];

	objects[0].name = "Березка"; objects[0].location = "Солигроск"; objects[0].health_profile = "Осанка"; objects[0].vouchers = 155;
	objects[1].name = "Росинка"; objects[1].location = "д.Мурашки"; objects[1].health_profile = "Осанка"; objects[1].vouchers = 247;
	objects[2].name = "Паласа"; objects[2].location = "д.Париж"; objects[2].health_profile = "Зависимости"; objects[2].vouchers = 102;
	objects[3].name = "Свитязь"; objects[3].location = "Минск"; objects[3].health_profile = "Опорный аппарат"; objects[3].vouchers = 20;
	objects[4].name = "Ивязь"; objects[4].location = "Слуцк"; objects[4].health_profile = "Зрение"; objects[4].vouchers = 6;
	int choice;

	while (true) {
		cout << "\t" << "Введите нужный вариант" << endl;
		cout << "\n1 - Поиск информации по названию";
		cout << "\n2 - Поиск информации по лечебному профилю";
		cout << "\n3 - Вывод всех существующих санаториев";
		cout << "\n4 - Выход из программы" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			string name;
			cout << "Введите название санатория...";
			cin.ignore();
			getline(cin, name);
			for (int i = 0; i < 5; i++)
			{
				objects[i].find_name(name);
			}
			break;
		}
		case 2: {
			string name;
			cout << "Введите лечебный профиль санатория...";
			cin.ignore();
			getline(cin, name);
			for (int i = 0; i < 5; i++)
			{
				objects[i].find_profile(name);
			}
			break;
		}
		case 3: {
			output(objects);
			cout << endl << endl;
			break;
		}
		default:
			break;
		}
	}
}