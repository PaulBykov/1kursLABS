#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stack
{
    int digit;
    stack* next;
};

void push(stack*& p, int value);
void show(stack* p);
void clear(stack*& p);
void read(stack*& p);


int main()
{
    setlocale(LC_CTYPE, "Russian");
    stack* first = nullptr;
    int value;

menu:

    int choice;
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод чисел из файла A.txt" << endl;
    cout << " 2 - Вывод чисел" << endl;
    cout << " 3 - Очистить стек" << endl;
    cout << " 4 - Выход" << endl;
    cin >> choice;
    switch (choice) {
        case 1: //ввод
            read(first);
            goto menu;
            break;
        case 2: //вывод
            show(first);
            goto menu;
            break;
        case 3: // Удалить элемент < 0
            stack * ppp;
            ppp = first;
            clear(ppp);
            goto menu;
            break;
        default:
            return 0;
            break;
    }


    return 0;
}


void push(stack*& p, int value) //Добавление символа в начало списка
{
    stack* newP = new stack;
    if (newP != NULL)     //есть ли место?  
    {
        newP->digit = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void show(stack* p) {
    if (p->next == NULL)
    {
        cout << "Список пуст!\n";
        return;
    }
    while (p != NULL) {
        cout << p->digit << " ";
        p = p->next;
    }
    cout << endl;
}

void clear(stack*& p) {
    p->next = NULL;
    p = NULL;
}

void read(stack*& p) {
    string buff;  stack* first = nullptr;
    ifstream frm("A.txt");
    if (frm.fail()){
        cout << "\n Ошибка открытия файла";
        exit(1);
    }

    int Min = 10000000;
    int i = 0, j = 0, len = 0;
    while (!frm.eof()){
        getline(frm, buff);
        i++;
        if (buff.length() < Min){
            Min = buff.length();
            j = i;
        }
        push(first, buff.length());
        len++;
    }
    frm.close();
    p = first;
    cout << "\nСписок считан из файла A.txt\n";

    show(first);
    cout << "Самая коротка строка номер - " << j - len + 1 << "\nЕё длинна - " << Min << endl;
}