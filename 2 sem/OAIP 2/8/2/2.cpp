#include "stdafx.h"
#include "myQueue.h"
#include <iostream>

using namespace std;    

struct Number
{
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
int minElem(Number* begin); //функция определения минимального элемента 
int maxElem(Number* begin); //функция определения максимального элемента 
void DeltoMin(Number** begin, Number** p); //функция удаления до минимального элемента 

int main()
{
    setlocale(LC_ALL, "Rus");

    Number* begin = NULL, * end, * t;
    t = new Number;
    int p, size;

    cout << "\nВведите длинну очереди: ";  cin >> size;
    cout << "Введите числа: ";       cin >> p;

    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;

    for (int i = 1; i < size; i++) //создание очереди
    {
        cin >> p;
        create(&begin, &end, p);
    }

    cout << "\nЭлементы очереди: \n";


    if (begin == NULL)   //вывод на экран
        cout << "Нет элементов" << endl;
    else
        view(begin);

    cout << "Кол-во чисел между мин и макс = " << abs(minElem(begin) - maxElem(begin)) - 1 << endl;


    return 0;
}



void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}

void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Очередь пуста!\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << " ";
            t = t->next;
        }
    cout << endl;
}

int minElem(Number* begin) //Опрделение минимального элемента
{
    Number* t = begin; int mn = 0, mnl = 0;

    int max;
    if (t == NULL)
    {
        cout << "Очередь пуста!\n"; return -1;
    }
    else
    {
        max = t->info;
        while (t != NULL)
        {
            if (t->info <= max)
            {
                max = t->info;
                mn = mnl;
            }
            t = t->next;
            mnl++;
        }
    }
    return mn;
}

int maxElem(Number* begin) //Опрделение минимального элемента
{
    Number* t = begin; int mn = 0, mnl = 0;

    int max;
    if (t == NULL)
    {
        cout << "Очередь пуста!\n"; return -1;
    }
    else
    {
        max = t->info;
        while (t != NULL)
        {
            if (t->info >= max)
            {
                max = t->info;
                mn = mnl;
            }
            t = t->next;
            mnl++;
        }
    }
    return mn;
}

void DeltoMin(Number** begin, Number** p) //Удаление до минимального элемента 
{
    Number* t;
    t = new Number;
    while (*begin != *p)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
