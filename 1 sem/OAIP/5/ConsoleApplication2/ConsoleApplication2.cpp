#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    double a = 2e-3;
    double b = 8.5;
    double n = 2.0;
    double i, y, z;
    cout << "for: \n";
    for (int j = 0; j < 3; j++) {
        cout << "i = "; cin >> i;
        y = sqrt(i * b - b * b * a);
        z = y * tan(0.5) - exp(1 + b);
        cout << "y = " << y << "\t" << "z = " << z << endl;
    }
    
    cout << "While: \n";
    i = 1.0;
    while (i <= 3)
    {
        y = sqrt(i * b - b * b * a);
        z = y * tan(0.5) - exp(1 + b);
        cout << "y = " << y << "\t" << "z = " << z << endl;
        i += 0.5;
    }

    b = 2.0;

    while (b <= 3) {
        for (int g = 0; g < 4; g++) {
            cout << "n = ";  cin >> n;
            y = sqrt(i * b - b * b * a);
            z = y * tan(n/4) - exp(1 + b);
            cout << "y = " << y << "\t" << "z = " << z << endl;
        }   
        b += 0.5;
    }


    return 0;
}
