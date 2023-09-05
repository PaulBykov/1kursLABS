#include <iostream>    
#include <fstream>
#include <string>


# define str_len 30                               
# define size 30  

using namespace std;

void enter_new();
void del();
void change();
void out();
void file_print();

struct Client
{
	char pass[str_len];
	int numb;
	char datein[9];
	char dateout[9];
	char type[str_len];

};

struct Client list_of_clients[size];
struct Client bad;

int current_size = 0; int choice;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для изменения записи" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "5-для ввода из файла" << endl;
	cout << "6-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
			case 1:  del();	break;
			case 2:  enter_new();  break;
			case 3:  change();  break;
			case 4:  out();	break;
			case 5: file_print(); break;
		}
	} while (choice != 6);
}

void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << endl << "Серия и номер паспорта: " << endl;
		cin >> list_of_clients[current_size].pass;

		cout << "Дата заезда " << endl;
		cin >> list_of_clients[current_size].datein;
		cout << "Дата выезда" << endl;
		cin >> list_of_clients[current_size].dateout;

		cout << "Номер комнаты " << endl;
		cin >> list_of_clients[current_size].numb;
		
		cout << "Тип размещения?" << endl;
		cin >> list_of_clients[current_size].type;

		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_clients[de1] = list_of_clients[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_clients[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void change()
{
	int n, per;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1-для изменения фамилии" << endl;
		cout << "2-для изменения даты заезда" << endl;
		cout << "3-для изменения даты выезда" << endl;
		cout << "4-для изменения номера комнаты" << endl;
		cout << "5-для изменения типа размещения" << endl;
		cout << "6-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новые паспортные данные" << endl;
			cin >> list_of_clients[n - 1].pass;   break;
		case 2: cout << "Новая дата заезда" << endl;
			cin >> list_of_clients[n - 1].datein; break;
		case 3: cout << "Новая дата выезда" << endl;
			cin >> list_of_clients[n - 1].dateout; break;
		case 4: cout << "Новый номер комнаты" << endl;
			cin >> list_of_clients[n - 1].numb; break;
		case 5: cout << "Новый тип размещения" << endl;
			cin >> list_of_clients[n - 1].type; break;
		}
	} while (per != 6);
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void out()
{
	int sw, n;
	cout << "1-вывод одной строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;

	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		
		cout << "Паспортные данные: " << list_of_clients[n - 1].pass << endl;
		cout << "Дата заезда: " << list_of_clients[n - 1].datein << endl;
		cout << "Дата выезда: " << list_of_clients[n - 1].dateout << endl;
		cout << "Номер комнаты: " << list_of_clients[n - 1].numb << endl;
		cout << "Тип размещения: " << list_of_clients[n - 1].type << endl; 

	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Номер выводимой строки " << i + 1 << endl;

			cout << "Паспортные данные: " << list_of_clients[i].pass << endl;
			cout << "Дата заезда: " << list_of_clients[i].datein << endl;
			cout << "Дата выезда: " << list_of_clients[i].dateout << endl;
			cout << "Номер комнаты: " << list_of_clients[i].numb << endl;
			cout << "Тип размещения: " << list_of_clients[i].type << endl;

		}
	}

	cout << "Что дальше?" << endl;
	cin >> choice;
}


void file_print() {
	
	FILE* file;
	file = fopen("A.txt", "r");

	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		fscanf(file, "%s", &(list_of_clients[current_size].pass));
		fscanf(file, "%d", &(list_of_clients[current_size].datein));
		fscanf(file, "%d", &(list_of_clients[current_size].dateout));
		fscanf(file, "%d", &(list_of_clients[current_size].numb));
		fscanf(file, "%s", &(list_of_clients[current_size].type));

		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
	fclose(file);

}
