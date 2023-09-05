#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>

using namespace std;


struct Tree          //дерево
{
	int key;         //ключ
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key);  //Добавление нового элемента

Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
void delAll(Tree* t);             //Очистка дерева

Tree* readTreeFromFile(const string& filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Error: Failed to open file \"" << filename << "\"." << endl;
		return nullptr;
	}

	Tree* Root = nullptr;
	int key;
	file >> key;
	while (key >= 0)
	{
		Root = insertElem(Root, key);
		file >> key;
	}

	file.close();
	return Root;
}

void writeTreeToFile(Tree* t, ofstream& file) {
	if (!t) {
		file << "-1\n"; // отметка о конце поддерева
		return;
	}
	file << t->key << "\n";
	writeTreeToFile(t->Left, file);
	writeTreeToFile(t->Right, file);
}


int c = 0, rightLen = 0;;         //количество слов и длина правой ветки соответ.
Tree* Root = NULL; 	//указатель корня

int main()
{
	setlocale(0, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int key, choice;

	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	удаление элемента\n";
		cout << "4 -	вывод дерева\n";
		cout << "5 -	очистка дерева\n";
		cout << "6 -	ввод дерева из файла\n";
		cout << "7 -	вывод дерева в файл\n";
		cout << "8 -	выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";

		string filename;

		switch (choice) {
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			insertElem(Root, key); break;
		case 3:
			cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 4:
				if (Root) {
					cout << "По умолчанию: \n";
					view(Root, 0);
					cout << endl;
				}
				else {
					cout << "Дерево пустое." << endl;
				}
		case 5:
			delAll(Root);
			break;
		case 6:
			Root = nullptr;
			cout << "Введите имя файла: ";
			cin >> filename;

			Root = readTreeFromFile(filename);

			if (Root) {
				cout << "Дерево успешно загружено из файла." << endl;
			}
			else {
				cout << "Ошибка: не удалось загрузить дерево из файла." << endl;
			}
			break;
		case 7:
			if (Root) {
				cout << "Введите имя файла: ";
				cin >> filename;
				ofstream file(filename);
				if (!file.is_open()) {
					cout << "Ошибка: не удалось открыть файл для записи." << endl;
					break;
				}
				writeTreeToFile(Root, file);
				file.close();
				cout << "Дерево записано в файл "" << filename << ""." << endl;
			}
			else {
				cout << "Дерево пустое." << endl;
			}
			break;
		case 8:
			exit(0);
			break;
		}
	}

	return 0;

}


Tree* list(int i)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->Left = t->Right = NULL;
	return t;
}

void compare(Tree* prev, Tree* t) {
	prev = t;
}

Tree* insertElem(Tree* t, int key)  //Добавление нового элемента
{
	Tree* Prev = t;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key);           //создается новый узел 
		if (Prev->Left == NULL)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}


Tree* makeTree(Tree* Root)    //Создание дерева
{
	int n, key;
	cout << "Введите n: ";
	cin >> n;

	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: ";
		cin >> key;
		Root = list(key);	// установка указателя на корень
	}
	for (int i = 0; i < n; i++)               //добавление элементов
	{
		cout << "\nВведите ключ: ";
		cin >> key;  
		insertElem(Root, key);
	}
	return Root;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{

		rightLen++;
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ' << endl;;
		view(t->Left, level + 1);	//вывод левого поддерева
	}

}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}
