#include <iostream>

using namespace std;

char getSymbol(int n) {
    if (n == 1) {
        return 'A';
    }
    else {
        return (getSymbol(n - 1) - 'A' + 1) % 26 + 'A';
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Введите n: ";
    int n;
    cin >> n;

    char symbol = getSymbol(n);
    cout << "Символ под номером n = " << symbol << endl;

    return 0;
}
