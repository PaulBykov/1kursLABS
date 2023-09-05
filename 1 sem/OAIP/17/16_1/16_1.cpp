// 16_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

const int INF = -100000;

int MAX(int *A, int n, int *ind) {
    int MAX = INF;
    for (int i = 0; i < n; i++) {
        if (A[i] > MAX) {
            MAX = A[i];
        }
    }
    return MAX;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int* A, n;
    cout << "Введите n: " << endl;
    cin >> n;
    A = new int[n];
    cout << "Введите массив A: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i] = A[i];
        if (A[i] >= 0) {
            A[i] = INF;
        }
    }
    int ind = 0;
    int k = MAX(A, n, &ind);
    swap(A[ind], A[n-1]);
    cout << "Максимальный отрицательный элемент: " << k << endl;

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    
}

