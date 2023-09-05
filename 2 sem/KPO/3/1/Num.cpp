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
    map <unsigned short, string> month = { {1, "������"}, {2, "�������"}, {3, "����"}, {4, "������"}, {5, "���"}, {6, "����"}, {7, "����"}, {8,"������"}, {9, "��������"}, {10, "�������"}, {11, "������"}, {12, "�������"} };
    // ������� ������� ����������� �������� ������ ������ ������

    while (true) {
        if (!choice) { // ���� ����� 0, �� ��������� �������
            break;
        }
        return month[choice]; // ����, �����������, ��� ������������ ������ �������� ������
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
