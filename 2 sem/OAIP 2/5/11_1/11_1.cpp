#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

enum SHELF_LIFE {
    month = 1, halfYear, year, twoYear, fiveYear
};

struct Pawnshop {

    string surname;
    string nameProduct;
    int gradePrice;
    int price;
    string shelfLife;

    struct DATE {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 11;
    } date;

    void input() {
        cin.ignore();
        cout << "Фамилия клиента: ";
        getline(cin, surname);
        cout << "Выберите пункт назначения\n(1 - Месяц, 2 - Полгода, 3 - Год, 4 - Два года, 5 - Пять лет)\n";
        unsigned int variable;
        cin >> variable;
        switch (variable)
        {
        case SHELF_LIFE::month:
            shelfLife = "Месяц";
            break;
        case SHELF_LIFE::halfYear:
            shelfLife = "Полгода";
            break;
        case SHELF_LIFE::year:
            shelfLife = "Год";
            break;
        case SHELF_LIFE::twoYear:
            shelfLife = "Два года";
            break;
        case SHELF_LIFE::fiveYear:
            shelfLife = "Пять лет";
            break;
        default:
            cout << "Вы ввели неверное значение";
            break;
        }
        cin.ignore();
        cout << "Введите название товара: ";
        getline(cin, nameProduct);
        cout << "Введите оценочная сумма: ";
        cin >> gradePrice;
        cout << "Введите сумму: ";
        cin >> price;
        unsigned int day, month, year;
    repeatDate:
        cout << "Введите дату дд.мм.гггг: ";
        cin >> day >> month >> year;
        if (day < 25 && month < 13 && year < 2049) {
            date.day = day;
            date.month = month;
            date.year = year;
        }
        else {
            cout << "Вы неверно ввели дату";
            goto repeatDate;
        };

    }
    void output() {
        if (surname != "") {
            cout << "---------------------------------\n";
            cout << "Фамилия: " << surname << endl;
            cout << "Название продукта: " << nameProduct << endl;
            cout << "Оценочная цена: " << gradePrice << "$" << endl;
            cout << "Цена:" << price << "$" << endl;
            cout << "Дата: " << date.day << "." << date.month << "." << date.year << endl;
            cout << "Срок хранения: " << shelfLife << endl;
            cout << "---------------------------------\n";

        }
    }

    void del() {
        surname = "";
        nameProduct = "";
        gradePrice = 0;
        price = 0;
        date.day = 0;
        date.month = 0;
        date.year = 0;
    }
    bool searh(string shelfLife) {
        if (this->shelfLife == shelfLife) {
            return true;
        }
        else {
            return false;
        }

    }
};

int main()
{

    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int variable, num;
    Pawnshop pawnshop[10];

    do
    {
        cout << "1 - Ввод новых залогов\n"
            << "2 - Вывод всех залогов\n"
            << "3 - Удалить залог\n"
            << "4 - Поиск залога\n"
            << "0 - Выход\n";
        cout << "Выберите опцию: ";
        cin >> variable;
        switch (variable)
        {
        case 1:
        {
            cout << "Введите кол-во залогов, которое хотите ввести: ";
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                pawnshop[i].input();
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < 10; i++)
            {
                pawnshop[i].output();
            }
            break;
        }
        case 3:
        {
            cout << "Введите списочный номер, который хотите удалить: ";
            cin >> num;
            for (int i = 0; i < 10; i++)
            {
                if (num == i)
                    pawnshop[i].del();
            }
            break;
        }
        case 4:
        {
            string shelfLife;
            cin.ignore();
            cout << "Введите срок хранения: ";
            getline(cin, shelfLife);

            for (int i = 0; i < 10; i++)
            {
                if (pawnshop[i].searh(shelfLife)) {
                    pawnshop[i].output();
                }
            }
            break;
        }
        default:
            cout << "Вы ввели не верное значение\n";
            break;
        }
    } while (variable != 0);


}


