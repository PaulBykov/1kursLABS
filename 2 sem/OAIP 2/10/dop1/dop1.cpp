#include <iostream>
#include <cmath>
#include <string>


using namespace std;

const int number[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void out(int* arr, int a) {
    for (int k = 0; k < a; k++)
        cout << arr[k];
    cout << "\n";
}

bool isMax(int* arr, int a) {
    for (int t = 0; t < a; t++) {
        if (arr[t] != a) {
            return false;
        }
    }
    return true;
}

void loop(int* &arr, int left, int a) {
    while (left < a) {
        if(left > 0)
            loop(arr, left - 1, a);
        if(arr[left] == a) {
            if (isMax(arr, a)) {
                out(arr, a);
                exit(1);
            }
            arr[left] = 0;
            arr[left + 1]++;
            if (arr[left + 1] > a) {
                arr[left + 1] = a;
                break;
            }
        }
        else {
            out(arr, a);
            arr[left]++;
        }
    }
    
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    setlocale(LC_ALL, "Rus");

    int a;
    cin >> a;
    if (a > 9 || a < 1) {
        cout << "A - должно быть цифрой! " << endl;
        return 1;
    }
    int* arr{new int[a]};
 
    for (int i = 0; i < a; i++)
        arr[i] = 0;

    loop(arr, a - 1, a);

    return 0;
}