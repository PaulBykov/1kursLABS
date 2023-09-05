#include <iostream>
#include <cmath>

using namespace std;


double ur1(double x) {
    return exp(x) - 3 - 1.0 / x; // в1 x * x + 4 * x – 2    в4 x * x * x + 2 * x – 1      в5    exp(x) - 3 - 1.0 / x
}

double ur2(double x) {
    return 0.2 - x * x; // в1 sin(x) + 0.1     в4 exp(x) - 2          в5 0.2 - x * x
}

void dih(double a, double b, double(* f)(double x)) {
    
    const double epsilon = 1e-3;
    double c;

    while (b - a > epsilon) {
        c = (a + b) / 2;
        if (f(b) * f(c) < 0)
            a = c;
        else
            b = c;
    }
    
    cout << (a + b) / 2 << endl;
    
}


int main()
{
    setlocale(LC_ALL, "Rus");
    double a, b;
    cout << "Ввод a, b для уравнения 1" << endl;
    cin >> a >> b;
    dih(a, b, ur1);

    cout << "Ввод a, b для уравнения 2" << endl;
    cin >> a >> b;
    dih(a, b, ur2);
}
