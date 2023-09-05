#include<iostream> 
#include <string>

using namespace std;

struct Number
{
    double info;
    Number* next;
};

void create(Number** begin, Number** end, double p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
void Del(Number** begin, Number** p);
void toRight(Number** begin, Number** end);
double MAX(Number* begin);

int main()
{
    setlocale(LC_ALL, "Rus");

    Number* begin = NULL, * end, * t;
    t = new Number;
    double p;int size;


    string s;

    cout << "Введите длинну очереди: " << endl;
    cin >> size;

    cout << "Введите очередь: ";

    cin >> p;

    t->info = p;  //первый элемент
    t->next = NULL;
    begin = end = t;

    for(int i = 0; i < size - 1; i++)
    {
        double temp;
        cin >> temp;
        create(&begin, &end, temp);
    }
    
    view(begin);

    toRight(&begin, &end);

    view(begin);

    return 0;
}

void create(Number** begin, Number** end, double p) //Формирование элементов очереди
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

void Del(Number** begin, Number** p) //Удаление очереди
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

void toRight(Number** begin, Number** end){
    Number* t = *begin;
    Number* t2 = *begin;
    double temp;
    while (t2->info != MAX(*begin)) {
        temp = t->info;
        while(t->next != NULL){
            swap(temp, t->next->info);
            t = t->next;
        }
        t2->info = temp;
    }
}


double MAX(Number* begin) {
    Number* t = begin;
    double m = -900;
    if (t == NULL)
    {
        cout << "Очередь пуста!\n";
        return -1;
    }
    else
        while (t != NULL)
        {
            if (t->info >= m) {
                m = t->info;
            }
            t = t->next;
        }
    return m;
}

