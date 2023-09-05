#include "stdafx.h"
#include "List.h"
#include <iostream>


using namespace std;


struct Person
{
	char name[20];
	int age;
	Person* next;
};

void print(void* b)       //Функция используется при выводе 
{
	Person* a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}

int menu() {
	setlocale(LC_ALL, "Rus");
	
	cout << "Меню:" << endl;
	cout << "1) Вывод + кол-во элементов" << endl;
	cout << "2) Удалить весь список" << endl;
	int temp;
	cin >> temp;
	return temp;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Person d = { "delete", 0 };

	Person a1 = { "Петров", 20 };
	Person a2 = { "Сидоров", 25 };
	Person a3 = { "Гончаров", 47 };

	Object L1 = Create();   // создание списка с именем L1

	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);

	while (true) {
		switch (menu()) {
		case 1:
			L1.PrintList(print);
			cout << "\nКоличество элементов списка: " << L1.CountList(&(L1.Head)) << endl;
			break;
		case 2:
			L1.DeleteList(&(L1.Head), (L1.GetLast()), L1.CountList(&(L1.Head)));
			break;
		default:
			exit(1);
		}
	}
	
	/*

	Element* e = L1.Search(&a3);
	Person* aa = (Person*)e->Data;

	cout << "Найден элемент= " << aa->name << endl;
	rc = L1.Delete(&a2);
	if (rc == true) cout << "Удален элемент" << endl;
	cout << "Список:" << endl;
	L1.PrintList(print);

	*/

	return 0;
}
