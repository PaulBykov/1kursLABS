#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double d = 0, a = 1.72, b = -0.05, z = 0;
    int i = -5;
    while (i <= 5) {
        if (i > 3 * b) {
            d = a + b * i;
        }
        else {
            d = tan(b) - a * i;
        }
        z = (a * d / 4) * (3 * a * b - exp(1 + d) / 100);
        cout << "d = " << d << " z = " << z << endl;
        i += 2;
    }
    return 0;

}

