#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m, k = 0, j = 0;

    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k ";
    cin >> k;

    const int INF = 1000;
    int A[INF];
    int *ind_a = A;

    cout << "Введите массив A: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *ind_a;
        if (*ind_a > k) {
            *ind_a = 1;
        }
        else if (*ind_a == k) {
            *ind_a = 0;
        }
        else {
            *ind_a = -1;
        }
        ind_a++;
    }
    cout << endl;
    cout << "> k :";
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            cout << i + 1 << " ";
        }
    }

    *ind_a = *A;
    cout << endl;
    cout << "== k ";
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            cout << i + 1 << " ";
        }
    }

    *ind_a = *A;
    cout << endl;
    cout << "< k ";
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}
