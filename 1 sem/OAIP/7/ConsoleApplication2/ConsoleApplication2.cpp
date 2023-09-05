#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ЭТО БАЗА
    setlocale(LC_ALL, "Rus");

    vector<double> base_nubmers(4);

    base_nubmers[0] = 0.9;
    base_nubmers[1] = 0.5;
    base_nubmers[2] = -2;
    base_nubmers[3] = -0.1;

    double g, c = -0.045;
    long long m = 4, j = 1;
    double multiplicated = 1;

    for (j = 1; j <= m; j++) {
        multiplicated *= (base_nubmers[j - 1] + 1) * (base_nubmers[j - 1] + 1);
    }
    cout << "g = " << c * multiplicated << endl;


    // ВАР 5
    long long a = 1.5, b = -4.15;

    vector<double> base_nubmers5(5);

    base_nubmers5[0] = 1;
    base_nubmers5[1] = 1.5;
    base_nubmers5[2] = -4;
    base_nubmers5[3] = -1.9;
    base_nubmers5[4] = 3;

    for (int i = 0; i < 5; i++) {
        if (base_nubmers5[i] > 0) {
            cout << "w[i] = " << a + base_nubmers5[i] << endl;
        }
        else {
            cout << "w[i] = " << b / base_nubmers5[i] << endl;
        }
    }


    // Вар 10
    double q, sum = 0;

    vector<double> x_list(6);
    vector<double> y_list(6);

    x_list[0] = 3; x_list[1] = -2; x_list[2] = 0.7; x_list[3] = -1; x_list[4] = -2; x_list[5] = 7;
    y_list[0] = 1; y_list[1] = 5; y_list[2] = -1.2; y_list[3] = 6; y_list[4] = 9; y_list[5] = -4;

    int count = 6;

    for (int i = 0; i < count; i++) {
        sum += x_list[i] * y_list[i];
    }
    cout << "sum = " << sum << endl;
}
