
#include <iostream>
#include <string>

using namespace std;

enum DESTINATION {
    Minsk = 1, Moscow, Kiev, Berlin, Paris, London, New_York
};

struct Flights {
    string destination;
    int numFlight;
    int priceTicket;
    int numberPlace;

    struct TIME {
        unsigned int hour : 5;
        unsigned int minute : 6;
    } time;

    struct DATE {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 11;
    } date;

    void input() {
        cin.ignore();
        cout << "Введите номер: ";
        cin >> numFlight;
        cout << "Выберите пункт назначения\n(1 - Минск, 2 - Москва, 3 - Киев, 4 - Берлин, 5 - Париж, 6 - Лондон, 7 - Нью-Йорк)\n";
        unsigned int variable;
        cin >> variable;
        switch (variable)
        {
        case DESTINATION::Minsk:
            destination = "Минск";
            break;
        case DESTINATION::Moscow:
            destination = "Москва";
            break;
        case DESTINATION::Kiev:
            destination = "Киев";
            break;
        case DESTINATION::Berlin:
            destination = "Берлин";
            break;
        case DESTINATION::Paris:
            destination = "Париж";
            break;
        case DESTINATION::London:
            destination = "Лондон";
            break;
        case DESTINATION::New_York:
            destination = "Нью-Йорк";
            break;
        default:
            cout << "Вы ввели неверное значение";
            break;
        }
        cin.ignore();
        cout << "Введите цену: ";
        cin >> priceTicket;
        cout << "Введите кол-во мест: ";
        cin >> numberPlace;
        unsigned int day, month, year, hour, minute;
    repeatTime:cout << "Введите время чч:мм: ";
        cin >> hour >> minute;
        if (hour < 25 && minute < 61) {
            time.hour = hour;
            time.minute = minute;
        }
        else {
            cout << "Вы неверно ввели время";
            goto repeatTime;
        }
    repeatDate:cout << "Введите дату дд.мм.гггг: ";
        cin >> day >> month >> year;
        if (day < 33 && month < 13 && year < 2049) {
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
        if (destination != "") {
            cout << "---------Номер рейса: " << numFlight << "-------------" << endl;
            cout << "Пункт назначения: " << destination << endl;
            cout << "Цена билета: " << priceTicket << endl;
            cout << "Кол-во мест" << numberPlace << endl;
            cout << "Время: " << time.hour << ":" << time.minute << endl;
            cout << "Дата: " << date.day << "." << date.month << "." << date.year << endl;

        }
    }

    void del() {
        numFlight = 0;
        destination = "";
        priceTicket = 0;
        numberPlace = 0;
        time.hour = 0;
        time.minute = 0;
        date.day = 0;
        date.month = 0;
        date.year = 0;
    }
    bool searh(int day, int month, int year) {
        if (date.day == day && date.month == month && date.year == year) {
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
    int variable, num;
    Flights flights[10];

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
        {
            cout << "Введите списочный номер, который хотите удалить: ";
            cin >> num;
            for (int i = 0; i < 10; i++)
            {
                if (num == i)
                    flights[i].del();
            }
            break;
        }
        case 4:
        {
            int day, month, year;
            cout << "Введите дату дд.мм.гггг: ";
            cin >> day >> month >> year;
            if (day < 33 && month < 13 && year < 2049) {
                day = day;
                month = month;
                year = year;
            }

            for (int i = 0; i < 10; i++)
            {
                flights[i].searh(day, month, year);
            }
            break;
        }
        default:
            cout << "Вы ввели не верное значение\n";
            break;
        }
    } while (variable != 0);


}


