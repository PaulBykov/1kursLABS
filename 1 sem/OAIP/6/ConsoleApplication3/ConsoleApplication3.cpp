#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Вар 1
    vector<int> a(6);
    a[0] = 13; a[1] = 17; a[2] = 19; a[3] = 23; a[4] = 29; a[5] = 31;
    setlocale(LC_ALL, "Rus");
    for (int i = 0; i < 6; i++) {
        int b = a[i] * a[i];
        if (b % 10 > (b / 10) % 10) {
            if ((b / 10) % 10 > b / 100) {
                cout  << "Данное число: " << a[i] * a[i] << endl;
            }
        }
    }


    // Вар 3

    double c1, c2;
    cout << "Введите c1, c2: ";
    cin >> c1 >> c2;
    for (int i = 0; i < 8; i++) {
        c2 += c1 / 2;
        c1 /= 2;
        i++;
        c1 += c2 / 2;
        c2 /= 2;
    }
    cout << "В первом сосуде: " << c1 << endl;
    cout << "Во втором сосуде: " << c2 << endl;


    // Вар 6
    int n, i = 2;
    cout << "Введите n: " << endl;
    cin >> n;
    cout << "1" << " ";
    while (i * i <= n)
        if (n % i == 0) {
            cout << i << " ";
            n /= i; 
        }
        else
            i++;
    if (n > 1)
        cout << n;

    return 0;
}
