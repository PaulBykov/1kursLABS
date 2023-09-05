#include <iostream>
#include <fstream>

using namespace std;

struct list
{
    double digit;
    list* next;
};

void insert(list*& p, double value);
void write(list*& p);
void read(list*& p);
void out(list* p);
void del(list*& p);
int search(list* p, double temp);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = nullptr;
    double value;

menu:

    int choice;
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод чисел" << endl;
    cout << " 2 - Вывод чисел" << endl;
    cout << " 3 - Запись списка в файл" << endl;
    cout << " 4 - Чтение списка из файла" << endl;
    cout << " 5 - Удалить элемент" << endl;
    cout << " 6 - Поиск элемента по значению" << endl;
    cout << " 7 - Выход" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Введите количество переменных: " << endl;
        int n;
        cin >> n;
        cout << "Введите n чисел типа double: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> value;
            insert(first, value);
        }
        goto menu;
        break;
    case 2:
        out(first);
        goto menu;
        break;
    case 3:
        write(first);
        goto menu;
        break;
    case 4:
        read(first);
        goto menu;
        break;
    case 5:
        list * pp;
        pp = first;
        cout << "Введите ИНДЕКС элемента который хотите удалить" << endl;
        int ind;
        cin >> ind;
        for (int i = 0; i < ind - 1; i++) {
            pp = pp->next; //он не пустой, не ври. Просто начинает с nullptr
        }
        del(pp);
        goto menu;
        break;
    case 6:
        cout << "Введите значение элемента: " << endl;
        double temp;
        cin >> temp;
        cout << "ИНДЕКС искомого элемента = " << search(first, temp) << endl;
        goto menu;
        break;
    default:
        return 0;
        break;
    }


    return 0;
}


void insert(list*& p, double value) //Добавление символа в начало списка
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->digit = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void out(list* p) {
    double avg = 0;
    int j = 0;
    if (p == NULL)
    {
        cout << "Список пуст!\n";
        return;
    }
    while (p != NULL) {
        if (p->digit < 0) {
            avg += p->digit;
            j++;
        }
        cout << p->digit << " ";
        p = p->next;
    }
    cout << "\n Среднее значение отрицательных элементов списка = " << avg / j << endl;
}




void write(list*& p) //запись в файл
{
    double buff;  list* first = nullptr;
    ofstream frm("A.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (p != NULL) {
        frm << p->digit << " ";
        p = p->next;
    }
    frm.close();
    p = first;
    cout << "\nСписок записан в файл A.txt\n";
}

void read(list*& p)  //Считывание из файла
{
    double buff;  list* first = nullptr;
    ifstream frm("A.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (!frm.eof())
    {
        frm >> buff;
        insert(first, buff);
    }
    frm.close();
    p = first;
    cout << "\nСписок считан из файла A.txt\n";
}



void del(list*& p) {
    p->next = (p->next)->next;
}


int search(list* p, double temp) {
    int i = 0;
    while (p != NULL) {
        if (p->digit == temp) {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}