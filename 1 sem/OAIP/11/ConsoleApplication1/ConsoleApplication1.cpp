#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите длинну массива: " << endl;
    int n; cin >> n;
    const int INF = 1000;
    int A[INF], B[INF];
    int* ind_a = A, * ind_b = B;
    cout << "Введите массив A: " << endl;
    for (int i = 0; i < n; i++, ind_a++) {
        cin >> *ind_a;
    }

    cout << "Введите массив B: " << endl;
    for (int i = 0; i < n; i++, ind_b++) {
       cin >> *ind_b;
    }


    int *ind_a1 = A, *ind_b1 = B;

    for (int i = 0; i < n; i++) {
        cout << *ind_a1 + *ind_b1 << " ";
        ind_a1++;
        ind_b1++;
    }
    return 0;
}
