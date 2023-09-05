#include <iostream>
#include <cstdlib>

const int INF = 255;
using namespace std;
int B[INF] = {};
int ind = 0;

void MAX(int *B, int &ind) {
    ind = 0;
    int local_max = B[0];
    for (int i = 0; i < INF; i++) {
    
        if (local_max < B[i]) {
            local_max = B[i];
            ind = i;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int *A, n, k;
    cout << "Введите k: " << endl;
    cin >> k;
    cout << "Введите n: " << endl;
    cin >> n;
    A = new int [n + 1];
    cout << "Введите массив: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(A + i);
        *(B +  *(A + i) ) += 1;
    }

    for (int i = 0; i < k; i++) {
        MAX(B, ind);
        cout << "Чаще всего встречается: " << ind << endl;
        cout << "Шанс выпадения этого значения: " << (B[ind] / (n * 1.0)) * 100 << "%" << endl;
        B[ind] = -1;  
            
    }

}

