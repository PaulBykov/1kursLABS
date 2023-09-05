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

    int state = 0;
    int count = 0;
    for (int i = 0; i < n && state < 3; i++) {
        if (i > 0) {
            if (a[i] != a[i - 1]) {
                state++;
            }
        }
        else {
            state++;
        }
                
        count ++;
    }

    cout << count;


    return 0;
}
