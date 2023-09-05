#include<iostream> 
#include <fstream>
#include <string>

using namespace std;

struct Number
{
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
void Del(Number** begin, Number** p);

ifstream frm("f.txt");
ofstream out("g.txt");

int main()
{
    setlocale(LC_ALL, "Rus");

    Number* begin = NULL, * end, * t;
    t = new Number;
    int p, size;


    string s;

    size = 1000;
    p = -1000;

    t->info = p;  //первый элемент
    t->next = NULL;
    begin = end = t;

    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (!frm.eof())
    {
        getline(frm, s);
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                create(&begin, &end, s[i] - '0');
            }
            else {
                out << s[i];
            }
        }
        view(begin);
        Del(&begin, &end);
    }
    frm.close();


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
    static int count;
    Number* t = begin;
    if (count != 0) {
        t = t->next;
    }
    if (t == NULL)
    {
        out << "Очередь пуста!\n";
        return;
    }
    else
        while (t != NULL)
        {
            if (t->info == -1000) {
                t = t->next;
                continue;
            }
            out << t->info;
            t = t->next;
        }
    out << endl;
    count++;
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