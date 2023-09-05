#include <iostream>
#include <cmath>

using namespace std;

double integrate(double x) {
    return sin(x) * sin(x) + 1; // Вар1: x * x * x - 3    Вар 15: sin(x) * sin(x) + 1    Вар10:   x * x - 4
}


int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Метод трапеций: " << endl;

    double a, b, n = 200, h, x, s;
    cout << "Введите a, b: " << endl;
    cin >> a >> b;

    h = (b - a) / n;
    x = a;
    s = (integrate(x) + integrate(x + n * h)) / 2;

    for (int i = 1; i < n; i++) {
        s += integrate(x);
        x += h;
    }

    s *= h;

    cout << s << endl;



    // Метод парабол
    cout << "Метод парабол: " << endl;

    h = (b - a) / n;
    x = a;
    s = integrate(x) + integrate(x + 2 * n * h);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            s += 4 * integrate(x);
        }
        else {
            s += 2 * integrate(x);
        }
        x += h;
    }

    s *= h / 3;

    cout << s << endl;

}
