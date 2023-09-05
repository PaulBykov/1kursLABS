#include <iostream>

using namespace std;

void negativ(int **A, int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] *= -1;
        }
    }
    
} 


int main()
{
    setlocale(LC_ALL, "Rus");
    int** A, n, m, sum = 0;
    cout << "Введите n: " << endl;
    cin >> n;
    cout << "Введите m: " << endl;
    cin >> m;
    A = new int* [n];
    bool Reverse = false;
    cout << "Введите массив: " << endl;
    for (int i = 0; i < n; i++) {
        bool is_neg = false;
        A[i] = new int[n];
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] < 0) {
                is_neg = true;
            }
        }
        if (!is_neg) {
            Reverse = true;
        }
    }

    if (Reverse) {
        negativ(A, n, m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }


}
