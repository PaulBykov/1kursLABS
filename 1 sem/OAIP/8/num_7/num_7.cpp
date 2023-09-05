#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return sin(x) + x + 2; // вар1: x * x * x + x – 3     вар15: sin(x) + x + 2    вар 10: x * x * x + x – 4
}

double f(double x) {
    return cos(x) + 1; // вар1: 3 * x * x + 1       вар15: 3 * x * x + 3      вар10: 3 * x * x + 1
}

double ff(double x) {
    return (-1) * sin(x); // вар1: 6 * x         вар15: 6 * x       вар10: 6 * x
}

int main()
{
    double a, b, e = 0.0001, x, x1;
    cin >> a >> b;

    if (func(a) * ff(a) > 0) {
        x1 = a;
    }
    else {
        x1 = b;
    }

    do {
        x = x1;
        x1 = x - func(x) / f(x);
    } while (abs(x1 - x) > e);

    cout << x1 << endl;


    // Дихотамия
    cin >> a >> b;
    do {
        x = (a + b) / 2;
        if (func(a) * func(x) <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    } while ( abs(a - b) > 2 * e );

    cout << x << endl;

}
