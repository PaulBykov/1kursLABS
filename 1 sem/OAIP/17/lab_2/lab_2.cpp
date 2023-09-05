#include <iostream>

using namespace std;

int sum = 0;
void zero_counter(int** A, int& n, int& m, int& sum);

int main()
{
    setlocale(LC_ALL, "Rus");
    int** A, n, m, sum = 0;
    cout << "Введите n (кол-во строк): " << endl;
    cin >> n;
    cout << "Введите m (кол-во столбцов): " << endl;
    cin >> m;
    A = new int *[n];
    cout << "Введите массив: " << endl;
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    zero_counter(A, n, m, sum);
    cout << "Кол-во строк с нулевым элементом: " << sum << endl;

}


void zero_counter(int **A, int &n, int &m,int &sum) {
    sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (A[i][j] == 0) {
                sum += 1;
                break;
            }

        }
    }

}
