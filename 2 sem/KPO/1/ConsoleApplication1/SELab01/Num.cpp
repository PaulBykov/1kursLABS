#include <iostream>


using namespace std;


inline int DayNum(int day, int month, bool year) {
    int DayNumber = 0;
    for (int i = 1; i < month; i++) {

        if (i == 1) {
            DayNumber += 31;
        }
        if (i == 2 && year) {
            DayNumber += 29;
        }
        else if (i == 2) {
            DayNumber += 28;
        }
        if (i == 3) {
            DayNumber += 31;
        }
        else if (i == 4) {
            DayNumber += 30;
        }
        else if (i == 5) {
            DayNumber += 31;
        }
        else if (i == 6) {
            DayNumber += 30;
        }
        else if (i == 7) {
            DayNumber += 31;
        }
        else if (i == 8) {
            DayNumber += 31;
        }
        else if (i == 9) {
            DayNumber += 30;
        }
        else if (i == 10) {
            DayNumber += 31;
        }
        else if (i == 11) {
            DayNumber += 30;
        }

    }

    DayNumber += day;

    return DayNumber;
}