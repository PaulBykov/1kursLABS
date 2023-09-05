#include <iostream>
#include <cmath>

using namespace std;

int fmin(int n, ...) {
    int* p = &n;
    int Min = 1000000;
    p+=2;
    for (int i = 0; i < n; i++, p+=2) {
        
        if (*p < Min) {
            Min = *p;
        }
    
        
    }
    return Min;
};


int mn(int n, ...) {
    int* p = &n;
    int Max = -1000000;
    p += 2;
    for (int i = 0; i < n; i++, p += 2) {

        if (*p >= Max) {
            Max = *p;
        }


    }
    return Max;
}


int kvadr(int n, ...) {
    int* p = &n;
    p += 2;
    int count = 0;
    for (int i = 0; i < n; i++, p += 2) {

        if (sqrt(*p) == (int) sqrt(*p)) {
            count++;
        }


    }
    return count;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Минимум: " << fmin(6, 1, 2, 3, 4, 5, 0) << endl;
    cout << "Минимум: " << fmin(5, 1, 2, 3, 4, 5) << endl;
    cout << "Минимум: " << fmin(4, 1, 2, 3, 4) << endl;

    cout << "Максимум: " << mn(6, 1, 2, 3, 4, 5, 0) << endl;
    cout << "Максимум: " << mn(5, 1, 2, 3, 4, 5) << endl;
    cout << "Максимум: " << mn(4, 1, 2, 3, 4) << endl;



    cout << "Кол-во целых квадратов: " << kvadr(6, 1, 2, 3, 4, 5, 9) << endl;
    cout << "Кол-во целых квадратов: " << kvadr(5, 1, 2, 3, 4, 5) << endl;
    cout << "Кол-во целых квадратов: " << kvadr(4, 1, 2, 3, 4) << endl;

}
