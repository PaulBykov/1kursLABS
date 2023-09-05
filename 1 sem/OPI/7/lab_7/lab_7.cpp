#include <iostream>

using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");

    char symbol;
    short number = 0;
    cin >> number;

    switch (number) {
    case(1):
        cin >> symbol;
        if ( isalpha(symbol) ) {
            cout << (int)symbol - (int)toupper(symbol);
        }
        else {
            cout << "Ошибка!";
        }
        break;
    case(2):
        cin >> symbol;
        if ( (int)symbol >= -96 ) {
            cout << (int)symbol - (int)toupper(symbol);
        }
        else {
            cout << "Ошибка!";
        }
        break;
    case(3):
        cin >> symbol;
        if ( isdigit(symbol) ) {
            cout << (int)symbol;
        }
        else {
            cout << "Ошибка!";
        }
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
