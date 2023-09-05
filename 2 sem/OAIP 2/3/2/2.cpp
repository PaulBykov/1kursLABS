#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    string str;
    fstream out("fA.txt", ios::out);

    getline(cin, str);
    out << str;
    int min_len = 1000000, len = 0, min_ind = 0;
    int i = 0;
    while(i < str.length()) {
        while (str[i] == '0' && i < str.length()) {
            i++;
        }

        int j = i;
        len = 0;
        while (str[j] != '0' && j < str.length()) {
            len++;
            j++;
        }

        if (len < min_len && len != 0) {
            min_len = len;
            min_ind = i;
        }
        i = j;
    }

    i = min_ind;
    while (str[i] != '0' && i < str.length()) {
        cout << str[i];
        i++;
    }
    out.close();

    return 0;
}
