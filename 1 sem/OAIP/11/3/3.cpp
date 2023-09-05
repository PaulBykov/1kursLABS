#include <iostream>

using namespace std;


void write(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, t, k = 0, j = 0;
    cout << "Введите длинну массива: " << endl; 
    cin >> n;
    const int INF = 1000;
    int A[INF], B[INF];
    cout << "Введите t ";
    cin >> t;
    cout << "Введите массив A: " << endl;

    int* inp_a = A, *inp_b = B;
    for (int i = 0; i < n; i++) {
        cin >> *inp_a;
        inp_a++;
    }

    cout << "Введите массив B: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *inp_b;
        inp_b++;
    }


    int* ind_a = A, * ind_b = B;

    for (int i = 0; i < n; i++) {
        if (*ind_a < t) {
            k++;
        }
        if (*ind_b < t) {
            j++;
        }
        ind_a++;
        ind_b++;
    }

    cout << endl;
    if (k >= j) {
        write(A, n);
        cout << endl;
        write(B, n);
    }
    else {
        write(B, n);
        cout << endl;
        write(A, n);
    }
    return 0;
}
