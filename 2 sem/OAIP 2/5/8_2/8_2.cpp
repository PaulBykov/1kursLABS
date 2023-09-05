
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

union TIME {
    unsigned int hour;
    unsigned int minute;
};

union _DATE {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct FLIGHTS_DATA
{
    string destination;
    int numFlight;
    int priceTicket;
    int numberPlace;
    struct TIME_DATA {
        unsigned int hour : 5;
        unsigned int minute : 6;
    } time_data = { 0, 0 };

    struct DATE_DATA {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 11;
    } date_data = { 0, 0, 0 };

    void input() {
        TIME time{};
        _DATE date{};
        cin.ignore();
        cout << "Введите номер: ";
        cin >> numFlight;
        cout << "Напишите пункт назначение: ";
        cin.ignore();
        getline(cin, destination);
        cout << "Введите цену: ";
        cin >> priceTicket;
        cout << "Введите кол-во мест: ";
        cin >> numberPlace;
    repeatTime:
        cout << "Введите время чч:мм: ";
        cin >> time.hour;
        if (time.hour < 25)
        {
            time_data.hour = time.hour;
        }
        else
        {
            cout << "Вы неверно ввели время\n";
            goto repeatTime;
        }
        cin >> time.minute;
        if (time.minute < 61)
        {
            time_data.minute = time.minute;
        }
        else
        {
            cout << "Вы неверно ввели время\n";
            goto repeatTime;
        }
    repeatDate:
        cout << "Введите дату дд.мм.гггг: ";
        cin >> date.day;
        if (date.day < 33) {
            date_data.day = date.day;

            date_data.year = date.year;
        }
        else {
            cout << "Вы неверно ввели дату\n";
            goto repeatDate;
        };
        cin >> date.month;
        if (date.month < 13)
        {
            date_data.month = date.month;
        }
        else {
            cout << "Вы неверно ввели дату\n";
            goto repeatDate;
        };
        cin >> date.year;
        if (date.year < 2049)
        {
            date_data.year = date.year;
        }
        else {
            cout << "Вы неверно ввели дату\n";
            goto repeatDate;
        };

    }
    void output() {
        if (destination != "") {
            cout << "---------Номер рейса: " << numFlight << "-------------" << endl;
            cout << "Пункт назначения: " << destination << endl;
            cout << "Цена билета: " << priceTicket << endl;
            cout << "Кол-во мест" << numberPlace << endl;
            cout << "Время: " << time_data.hour << ":" << time_data.minute << endl;
            cout << "Дата: " << date_data.day << "." << date_data.month << "." << date_data.year << endl;

        }
    }
    bool search(string destination) {
        if (destination == this->destination) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int variable, num;
    string destination;
    FLIGHTS_DATA flights[10];

    do
    {
        cout << "1 - Ввод новых рейсов\n"
            << "2 - Вывод имеющихся рейсов\n"
            << "3 - Удалить рейс\n"
            << "4 - Поиск рейса\n"
            << "0 - Выход\n";
        cout << "Выберите опцию: ";
        cin >> variable;
        switch (variable)
        {
        case 1:
        {
            cout << "Введите кол-во рейсов, которое хотите ввести: ";
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                flights[i].input();
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < 10; i++)
            {
                flights[i].output();
            }
            break;
        }
        case 3:
            getline(cin, destination);
            for (int i = 0; i < 10; i++)
            {
                bool flag = flights[i].search(destination);
            }
        }
    } while (variable != 0);
}