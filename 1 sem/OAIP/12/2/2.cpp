#include <iostream>
#include <string>

using namespace std;

const int INF = 1000;
string s1;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите предложение " << endl;
    getline(cin, s1);
    int k, n;
    cout << "Введите k " << endl;
    cin >> k;
    cout << "Введите n " << endl;
    cin >> n;
    for (int i = n - 1; i < n + k - 1; i++) {
        cout << s1[i];
    }

}

