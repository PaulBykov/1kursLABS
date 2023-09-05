#include <iostream>
#include <string>
using namespace std;

typedef unsigned int numbers;
typedef string names;
typedef bool yORn;

/*формат_файла (txt, pdf, …),
размер_файла, название_книги, автор, для детей (да/нет),
количество_страниц, дата_загрузки*/

struct book
{
    names format;
    names size;
    names name;
    names autor;
    yORn forkids;
    numbers count;
    names date;
};

bool operator>(book Subject1, book Subject2)
{
    if (Subject1.count > Subject2.count)
        return true;
    else return false;
};

bool operator<(book Subject1, book Subject2)
{
    if (Subject1.count < Subject2.count)
        return true;
    else return false;
};

int main()
{
    setlocale(LC_ALL, "Rus");
    book book1 = { "pdf", "64 Кбайт", "Преступление и наказание", "Фёдор Достоевский", false, 366, "09.04.2020"};
    book book2 = { "pdf", "1.1 Мбайт", "Моби Дик", "Герман Мелвилл", false, 704, "02.02.2021" };

    if (book1 > book2)
        cout << "Истина" << endl;
    else cout << "Ложь" << endl;

    if (book1 < book2)
        cout << "Истина" << endl;
    else cout << "Ложь" << endl;
}