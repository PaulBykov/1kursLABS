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
            s++; // Считаем кол-во слов
            continue;
        }
        k[s] += w[i]; // Каждая ячейка k будет заполнена отдельным словом
    }



    for (int i = 0; i <= s; i++) {
        if ((i + 1) % 2 == 0) { // Выбираем только каждое второе слово
            for (int j = k[i].length() - 1; j >= 0; j--) { // идём с конца слова и выводим по букве
                cout << k[i][j];
            }
            cout << " ";
        }
    }

    return 0;
}
