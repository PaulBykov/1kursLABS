#include <iostream>
#include <string>

using namespace std;

const int INF = 1000;
string s;
int i = 0;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите предложение " << endl;
    getline(cin, s);
    int n = s.length();
    int j = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            while (s[i] != ')' && s[i] != '}' && s[i] != ']') {
                i++;
            }
            i++;
        }
        if (i < n) {
            cout << s[i];
        }
    }

}