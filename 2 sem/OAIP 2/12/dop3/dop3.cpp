#include <iostream>
#include <windows.h>


using namespace std;


struct Tree          //дерево
{
	int key;         //ключ
	bool color; // false - черный		 true - красный
	Tree* Left, * Right;
};


Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key);  //Добавление нового элемента

Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
void delAll(Tree* t);             //Очистка дерева


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
		cout << "6 -	выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			insertElem(Root, key); break;
		case 3:
			cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 4:  
			if (Root->key >= 0)
			{
				cout << "Дерево повернуто на 90 град. влево" << endl;
				view(Root, 0);
			}
			else 
				cout << "Дерево пустое\n";
			break;

		case 5:  delAll(Root); break;
		case 6:  exit(0);
		}
	}

	return 0;

}



Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: ";
		cin >> key;
		Root = list(key);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите ключ: ";  
		cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		insertElem(Root, key);
	}
	return Root;
}

Tree* list(int i)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->color = false; // по умолчанию не красим её
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key)  //Добавление нового элемента
{
	Tree* Prev = t;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	bool color = false; // цвет предыдущей просмотренной вершины
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			color = !color;
			if (key < t->key)
				t = t->Left;
			else
				t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key);           //создается новый узел 
		if (key < Prev->key) {  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		}
		else
			Prev->Right = t;   // либо на правую 
	}
	t->color = color;
	return t;
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
		//баланс
		if (t->Right == NULL && t->Left == NULL) {
			t->color = 0;
		}


		rightLen++;
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << "(" << t->color << ")" << endl;;
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
