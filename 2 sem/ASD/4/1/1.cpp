#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compair(int a, int b) {
    return a > b;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите n: " << endl; cin >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), compair);

    int sum = 0;

    for (int i = 0; i <= n / 2; i++) {
        if (i == n / 2) {
            cout << a[i] << " ";
            sum += a[i];
            break;
        }
        cout << a[i] << " " << a[n - i - 1] << " ";
        sum += a[i];
    }

    cout << "\nМаксимальная сумма = " << sum << endl;

}
