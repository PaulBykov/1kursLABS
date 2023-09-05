#include <iostream>
#include <sstream>


using namespace std;

const int INF = 1023;
char w[INF];

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите строку " << endl;

    gets_s(w);
    int ln = 0, min_ln = 10000, min_ln_ind = 0;
    char* wi = w;

    for (int i = 0; i < strlen(w); i++) {
        while ((*(wi+i) == '1') && i < strlen(w)) {
            ln++;
            i++;
        }
        if (ln < min_ln && (*(wi + i - 1) == '1') && i < strlen(w)) {
            min_ln = ln;
            min_ln_ind = i;

        }
        ln = 0;
    }

    for (int i = min_ln_ind - min_ln; i < min_ln_ind; i++) {
        cout << *(wi + i);
    }
     
    return 0;
}

