#include <iostream>
#include <ctime>
#include <random>


using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");

    int n, m;
    float sum = 0, count = 0;

    cout << "Введите n, m " << endl;
    cin >> n >> m; 
    int **A;
    A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        cout << "Строка № " << i + 1 << "  : ";
        for (int j = 0; j < m; j++) {
            if (A[i][j] > 0) {
                sum += A[i][j];
                count++;
            }
        }
        cout << "Сумма положительных элементов: " << sum << " ";
        cout << "Кол-во положительных элементов: " << count << " ";
        cout << " Среднее арифметическое полож. элементов: " << sum / count << endl;
        count = 0;
        sum = 0;
    }
}
