#include "stdafx.h"
#include "Leap.cpp"
#include "Num.cpp"


using namespace std;

int main()
{
    char date[9];
    setlocale(LC_ALL, "Rus");
    cout << "Введите дату в формате ДДММГГГГ" << endl;
    cin >> date;
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[2] - '0') * 10 + (date[3] - '0');
    int year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + (date[7] - '0');
    
    if (day > 31 || month > 12 || day < 1 || month < 1) {
        cout << "Введены некоректные данные";
        return 0;
    }
    if (isLeap(year)) {
        cout << "Данный год високосный" << endl;
    }
    else {
        cout << "Данный год не високосный" << endl;
    }
    cout << "Порядковый номер дня в году = " << DayNum(day, month, isLeap(year)) << endl;
    
    int DaysUntil;

    if (264 - DayNum(day, month, isLeap(year)) >= 0) {
        DaysUntil = 121 - DayNum(day, month, isLeap(year));
    }
    else {
        DaysUntil = 365 - DayNum(day, month, isLeap(year)) + 121;
    }
    cout << "Дней до ближайшего дня рождения: " << DaysUntil << endl;

    system("pause");
    return 0;
}
