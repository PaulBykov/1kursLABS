#include <iostream>

using namespace std;

struct stack
{
    int digit;
    stack* next;
};

void push(stack*& p, int value);
void show(stack* p);
void pop(stack*& p);
void clear(stack*& p);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    stack* first = nullptr;
    int value;

menu:

    int choice;
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод чисел" << endl;
    cout << " 2 - Вывод чисел" << endl;
    cout << " 3 - Удалить элемент < 0" << endl;
    cout << " 4 - Очистить стек" << endl;
    cout << " 5 - Выход" << endl;
    cin >> choice;
    switch (choice) {
    case 1: //ввод
        cout << "Введите количество переменных: " << endl;
        int n; cin >> n;
        cout << "Введите n чисел типа int: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> value;
            push(first, value);
        }
        goto menu;
        break;
    case 2: //вывод
        show(first);
        goto menu;
        break;
    case 3: // Удалить элемент < 0
        stack * pp;
        pp = first;
        while (pp != NULL) {
            if ((pp->next)->digit < 0) {
                pop(pp);
                goto menu;
            }
            pp = pp->next;
        }
        cout << "Таких элементов нет! \n";
        goto menu;
        break;
    case 4: // очистить стек
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


void pop(stack*& p) {
    p->next = (p->next)->next;
}

void clear(stack*& p) {
    p->next = NULL;
    p = NULL;
}