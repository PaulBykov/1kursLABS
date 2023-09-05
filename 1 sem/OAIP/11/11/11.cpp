#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, k = 0;

    cout << "Введите n: ";
    cin >> n;

    const int INF = 1000;
    int A[INF];
    int* ind_a = A;

    cout << "Введите массив A: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *ind_a;
        ind_a++;
    }

    *ind_a = *A;
    for (int i = 1; true; i++) {
        bool z = false;
        int *inp = A;
        for (int j = 0; j < n; j++) {
            if (*inp == i) {
                z = true;
                break;
            }
            inp++;
        }
        if (!z) {
            cout << i;
            break;
        }
    }

    return 0;
}
