#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m, k = 0, j = 0;

    cout << "Введите n: ";
    cin >> n;

    const int INF = 1000;
    int A[INF], B[INF];
    int* ind_a = A, * ind_b = B;

    cout << "Введите m ";
    cin >> m;

    int MAX = -100000;
    cout << "Введите массив A: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *ind_a;
        if (*ind_a > MAX) {
            MAX = *ind_a;
        }
        ind_a++;
    }

    bool z = false;
    cout << "Введите массив B: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> *ind_b;
        if (*ind_b == MAX) {
            z = true;
        }
        ind_b++;
    }

    if (z) {
        cout << "Содержиться" << endl;
    }
    else {
        cout << "Не содержиться" << endl;
    }
    

    
    return 0;
}
