#include "stdafx.h"
#include <map>
#include <windows.h>
#include "Leap.cpp"

using namespace std;


inline int DayNum(int day, int month, bool year) {
    int DayNumber = 0;
    int DayCount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    
    if (isLeap(year)) {
        DayCount[1] = 29;
    }

    for (int i = 0; i < month - 1; i++) {
        DayNumber += DayCount[i];
    }
    
   
    DayNumber += day;

    

    return DayNumber - 1;
}


inline string NameOfMonth(int choice) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    map <unsigned short, string> month = { {1, "январь"}, {2, "‘евраль"}, {3, "ћарт"}, {4, "јпрель"}, {5, "ћай"}, {6, "»юнь"}, {7, "»юль"}, {8,"јвгуст"}, {9, "—ент€брь"}, {10, "ќкт€брь"}, {11, "Ќо€брь"}, {12, "ƒекабрь"} };
    // создали словарь соответсвий названию мес€ца номера мес€ца

    while (true) {
        if (!choice) { // если ввели 0, то завершить функцию
            break;
        }
        return month[choice]; // пока, гарантируем, что пользователь введет валидные данные
        break;
    }
}


inline void DateByNum(int number) {
    int DayCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    while (number > DayCount[i]) {
        number -= DayCount[i];
        i++;
    }
    i++;
    if (!number) {
        ++number;
    }
    cout << number << " " << NameOfMonth(i) << endl;
}
