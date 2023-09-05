#include <iostream>
#include <string>

using namespace std;

string w, k[1000002];


int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите предложение " << endl;
    getline(cin, w);
    int s = 0;

    for (int i = 0; i < w.length(); i++) {
        if (w[i] == ' ') {
            s++;
            continue;
        }
        k[s] += w[i];
    }

    bool z = true;

    for (int i = 0; i <= s; i++) {
        for (int j = 0; j < k[i].length(); j++) {
            if (!isdigit(k[i][j])) {
                z = false;
                break;
            }
        }
        if (z) {
            cout << k[i] << " ";
        }
        z = true;
    }

    cout << endl;
    z = true;

    for (int i = 0; i <= s; i++) {
        for (int j = 0; j < k[i].length(); j++) {
            if (!isalpha(k[i][j])) {
                z = false;
                break;
            }
        }
        if (z) {
            cout << k[i] << " ";
        }
        z = true;
    }

    cout << endl;
    z = true;
    bool z1 = true;

    for (int i = 0; i <= s; i++) {
        for (int j = 0; j < k[i].length(); j++) {
            if (isdigit(k[i][j])) {
                z = false;
            }
            if (isalpha(k[i][j])){
                z1 = false;
            }
        }
        if (!z && !z1) {
            cout << k[i] << " ";
        }
        z = true;
        z1 = true;
    }
    return 0;
}
