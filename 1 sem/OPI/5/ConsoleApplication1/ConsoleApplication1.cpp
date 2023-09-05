#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    char x, x1; char ter;
    int k = 0;
    cin >> k;
    switch (k) {
    case(1): 
        cin >> x;
        if (isalpha(x)) {
            cout << (int) x - (int)toupper(x);
        }
        else {
            cout << "Ошибка!";
        }
        break;
    case(2): 
        cin >> x;
        if ((int)x >= -96) {
            cout << (int)x - (int)toupper(x);
        }
        else {
            cout << "Ошибка!";
        }
        break;
    case(3): 
        cin >> ter;
        if (isdigit(ter)) {
            cout << (int) ter;
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


}
