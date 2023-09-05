#include <iostream>

using namespace std;

struct Guy
{
	bool isIn;
	int number;

	Guy* next;
	Guy* prev;
};


int menu()
{
	char s[80]; int c;
	cout << endl;
	cout << "1. Ввод" << endl;
	cout << "2. Вывод" << endl;
	cout << endl;
	cin >> c;
	return c;
}


void insert(Guy* e, Guy** phead, Guy** plast) //Добавление в конец списка
{
	Guy* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = *phead;
		(*phead)->prev = e;
		e->prev = p;
		*plast = e;
	}
}

Guy* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	static int i;
	Guy* temp = new  Guy();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	temp->isIn = true;
	temp->number = i;
	i++;

	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}


void outputList(Guy** phead, Guy** plast, int p, int n)      //Вывод списка на экран
{
	int i = 0, y = 0, k, people = n;
	Guy* t = *phead;
	while (people > 0){
		k = p;
		while (k > 0) {
			if (t->isIn) {
				k--;
			}
			t = t->next;
		}
		while (people > 0) {
			if (t->isIn) {
				t->isIn = false;
				people--;
				cout << "Удалили " << t->number << endl;
				break;
			}
			t = t->next;
		}
		t = t->next;
		y++;
		i++;
	}

	cout << endl;

}


int main()
{
	Guy* head = NULL;
	Guy* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:
			cout << "Введите n: " << endl;
			int n;
			cin >> n;
			for(int i = 0; i < n; i++)
				insert(setElement(), &head, &last);
			break;
		case 2: {
			cout << "Введите k: " << endl;
			int k;
			cin >> k;
			outputList(&head, &last, k, n);
			break;
		}
		default: exit(1);
		}
	}
	return 0;
}


