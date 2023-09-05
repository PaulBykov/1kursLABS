#include <iostream>    

# define str_len 30                               
# define size 8  

using namespace std;
void enter_new();
void del();
void change();
void out();

struct train
{
	char Goto[str_len];
	int numb;
	int time;
};

struct train train_list[size];

int current_size = 0; int choice;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;
	cout << "3-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();  break;
		case 2:  out();	break;
		}
	} while (choice != 3);
}

void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << endl << "Пункт назначения: " << endl;
		cin >> train_list[current_size].Goto;

		cout << "Время выезда: " << endl;
		cin >> train_list[current_size].time;

		cout << "Номер: " << endl;
		cin >> train_list[current_size].numb;

		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}


void out()
{
	int goTime;
	bool atLeastOne = false;
	cout << "Введите минимальное время отправления: " << endl;
	cin >> goTime;

	for (int i = 0; i < current_size; i++){ 
		if (train_list[i].time > goTime) {
			cout << endl;
			cout << "Номер: " << train_list[i].numb << endl;
			cout << "Пункт назначения: " << train_list[i].Goto << endl;
			cout << "Время выезда " << train_list[i].time << endl;
			atLeastOne = true;
		}
	}

	if (!atLeastOne) {
		cout << "Таких поездов нет! " << endl;
	}

	cout << "Что дальше?" << endl;
	cin >> choice;
}
