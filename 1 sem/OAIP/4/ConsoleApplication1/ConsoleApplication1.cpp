#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, c;
    cout << "Введите 3 числа: " << endl;
    cin >> a >> b >> c;
    if (a == b) {
        cout << "Есть" << endl;
    }
    else if(a == c) {
        cout << "Есть" << endl;
    }
    else if (b == c) {
        cout << "Есть" << endl;
    }
    else {
        cout << "Нет" << endl;
    }






    int x1, y1, x2;
    cout << "Введите 3 числа: " << endl;
    cin >> x1 >> y1 >> x2;
    if (x1 >= y1) {
        if (x1 >= x2) {
            cout << "max(x1, y1, x2) = " << x1;
        }
        else {
            cout << "max(x1, y1, x2) = " << x2;
        }
    }
    else {
        if (y1 >= x2) {
            cout << "max(x1, y1, x2) = " << y1;
        }
        else {
            cout << "max(x1, y1, x2) = " << x2;
        }
    }


}
