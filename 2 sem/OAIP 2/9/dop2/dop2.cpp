#include <iostream>

using namespace std;

const unsigned int NAME_SIZE = 30;
// курсы вывожу от меньшего к большему

struct Student
{
	char name[NAME_SIZE];
	char surname[NAME_SIZE];
	char lastname[NAME_SIZE];
	short year;
	short kurs;
	short group;
	short notes[5];

	Student* next;
	Student* prev;
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


void insert(Student* e, Student** phead, Student** plast) //Добавление в конец списка
{
	Student* p = *plast;
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
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

short MT, MG, yearMin = 3000, yearInd = 0, yearMax = 0, yearInd1;
int sumn = 0, prevsumn = 0, sumn_ind = 0;


Student* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Student* temp = new  Student();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите ФИО: ";
	cin >> temp->name >> temp->surname >> temp->lastname;
	cout << "Введите год рождения: ";
	cin >> temp->year;
	cout << "Введите номер группы: ";
	cin >> temp->group;
	if (temp->group > MG) {
		MG = temp->group;
	}
	cout << "Введите курс: ";
	cin >> temp->kurs;
	if (temp->kurs > MT) {
		MT = temp->kurs;
	}
	cout << "Введите отметки (5 шт.): " << endl;
	for(int j = 0; j < 5; j++)
		cin >> temp->notes[j];
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

double average(short a[], int count) {
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += a[i];
	}
	return sum / count;
}

void outputList(Student** phead, Student** plast)      //Вывод списка на экран
{
	int i = 0, y = 0;
	while (i <= MT) {
		Student* t = *phead;
		while (t)
		{
			if (t->year < yearMin) {
				yearMin = t->year;
				yearInd = i;
			}
			else if (t->year > yearMax) {
				yearMax = t->year;
				yearInd1 = i;
			}

			for (int j = 0; j < 5; j++) {
				sumn += t->notes[j];
			}
			if (sumn > prevsumn) {
				prevsumn = sumn;
				sumn_ind = y;
			}

			if (t->kurs == i) {
				cout << "-----------------" << endl;
				cout << t->name << " " << t->surname << " " << t->lastname << endl;
				cout << t->year << " " << t->kurs << "-" << t->group << endl;
			}
			t = t->next;
			y++;
		}
		i++;
	}
	i = 0;
	cout << "Средний балл групп: " << endl;
	Student* t = *phead;
	while (t != NULL) {
		cout << "\n" << t->group << ") ";
		for (int j = 0; j < 5; j++)
			cout << t->notes[j] << " ";
		i++;
		t = t->next;
	}

	cout << endl;

	

	cout << "Самый младший ученик - " << yearInd + 1 << endl;
	
	cout << "Самый старший ученик - " << yearInd1 + 1 << endl;

	cout << "Самый успешный ученик - "	<< sumn_ind << endl;
}


int main()
{
	Student* head = NULL;
	Student* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  
			insert(setElement(), &head, &last);
			break;
		case 2: {	
			outputList(&head, &last);
			break;
		}
		default: exit(1);
		}
	}
	return 0;
}


