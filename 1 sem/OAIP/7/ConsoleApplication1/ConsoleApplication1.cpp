#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int number, n;

    // Доп вар 2

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number < 0) {
            cout << i + 1 << endl;
            break;
        }
    }


    // Доп вар 6

    // Доп вар 7

    cout << " Номер 7 " << endl;

    cin >> n;

    int max_min = -1000000; // Стартовое значение принятое за бесконечно недосягаемое
    int max_max = 0;

    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number < 0 && max_min < number) {
            max_min = number;
        }
        else if (number > 0 && max_max < number) {
            max_max = number;
        }
    }


    if (max_min == -1000000) {
        cout << "Максимальный положительный: " << max_max << "\n" << "Нет отрицательных" << endl;
    }
    else {
        cout << "Максимальный положительный: " << max_max << "\n" << "Максимальный отрицательный: " << max_min << endl;
    }
    

    return 0;
}
