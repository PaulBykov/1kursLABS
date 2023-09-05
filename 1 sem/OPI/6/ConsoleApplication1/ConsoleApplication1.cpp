#include <iostream>
#include "case1.cpp"
#include "case2.cpp"
#include "case3.cpp"


using namespace std;


int main()
{

    setlocale(LC_ALL, "Rus");

    extern char symbol;
    int number = 0;
    cin >> number;

    switch (number) {
    case(1):

        case1();

        break;
    case(2):

        case2();

        break;
    case(3):

        case3();

        break;
    case(4):
        cout << "Вы вышли из программы!";
        break;
    default:
        cout << "Ошибка. Следуй инструкциям!";
        break;
    }


    return 0;
}
