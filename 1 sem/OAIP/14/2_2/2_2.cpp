#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");

    const int INF = 10000;

    int x[INF] = {};

    int n, m;

    cout << "Введите n, m " << endl;
    cin >> n >> m;

    int** A;
    A = new int* [n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {x
            cin >> *(*(A + i) + j);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(x + *(*(A + i) + j) ) = 1;
        }
    }

    int count = 0;

    for (int i = 0; i < INF; i++) {
        if (*(x+i) == 1) {
            count++;
        }
    }

    cout << count;

    return 0;
}
