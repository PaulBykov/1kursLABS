#include <iostream>
#include <sstream>

using namespace std;

const int INF = 1023;
char w[INF];

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите предложение " << endl;
    gets_s(w);
    int k, n;
    cout << "Введите k " << endl;
    cin >> k;
    cout << "Введите n " << endl;
    cin >> n;
    for (int i = n - 1; i < n + k - 1; i++) {
        cout << w[i];
    }

}

