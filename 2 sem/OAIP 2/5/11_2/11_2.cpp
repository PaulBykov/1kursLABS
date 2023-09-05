#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

union DATE_ISSUE {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct CAR_DATA
{
    string modelCar;
    string color;
    int numberFactory;
    string typeBodyCar;
    string owner;

    struct DATE_RELEASE {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 11;
    } date_data = { 0, 0, 0 };

    struct DATE_TECH_INSPECTION {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 11;
    } date_tech = { 0, 0, 0 };

    void setDate(unsigned int day, unsigned int month, unsigned int year) {

    }

    void input() {

        cout << "Напишите марку машины: ";
        cin.ignore();
        getline(cin, modelCar);
        cout << "Введите цвет: ";
        getline(cin, color);
        cout << "Введите тип кузова: ";
        getline(cin, typeBodyCar);
        cout << "Введите дату выпуска (дд.мм.гггг): ";
        DATE_ISSUE date{};
    repeatDate:


        cin >> date.day;
        if (date.day < 33) {
            date_data.day = date.day;
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
        cout << "Введите дату тех. осмотра (дд.мм.гггг): ";


        cin >> date.day;
        if (date.day < 33) {
            date_tech.day = date.day;
        }
        else {
            cout << "Вы неверно ввели дату\n";

        };
        cin >> date.month;
        if (date.month < 13)
        {
            date_tech.month = date.month;
        }
        else {
            cout << "Вы неверно ввели дату\n";

        };
        cin >> date.year;
        if (date.year < 2049)
        {
            date_tech.year = date.year;
        }
        else {
            cout << "Вы неверно ввели дату\n";

        };
        cout << "Введите владельца: ";
        cin.ignore();
        getline(cin, owner);

        cout << "Введите заводской номер: ";
        cin.ignore();
        cin >> numberFactory;
    }
    void output() {
        if (modelCar != "") {
            cout << "---------------------------------\n";
            cout << "Марка машины: " << modelCar << endl;
            cout << "Заводской номер: " << numberFactory << endl;
            cout << "Тип кузова: " << typeBodyCar << endl;
            cout << "Цвет машины: " << color << endl;
            cout << "Дата выпуска: " << date_data.day << " " << date_data.month << " " << date_data.year << endl;
            cout << "Дата тех. осмотра: " << date_tech.day << " " << date_tech.month << " " << date_tech.year << endl;
            cout << "Владелец: " << owner << endl;
            cout << "---------------------------------\n";
        }
    }
    bool search(string destination) {
        if (destination == this->modelCar) {
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
    CAR_DATA cars[10];

    do
    {
        cout << "1 - Ввод новых машин\n"
            << "2 - Вывод имеющихся машин\n"
            << "3 - Найти машину\n"
            << "0 - Выход\n";
        cout << "Выберите опцию: ";
        cin >> variable;
        switch (variable)
        {
        case 1:
        {
            cout << "Введите кол-во машин, которое хотите ввести: ";
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                cars[i].input();
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < 10; i++)
            {
                cars[i].output();
            }
            break;
        }
        case 3:
            cin.ignore();
            getline(cin, destination);
            for (int i = 0; i < 10; i++)
            {
                if (cars[i].search(destination)) {
                    cars[i].output();
                }
            }
            break;
        }
    } while (variable != 0);
}

