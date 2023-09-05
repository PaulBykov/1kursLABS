#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Вар 2
    int k, l, n, m;
    setlocale(LC_CTYPE, "Russian");
    cout << "Введите значения k, l ";
    cin >> k >> l;
    cout << "Введите значения m, n ";
    cin >> m >> n;
    if (min(min(k, l), min(m, n)) >= 1 || max(max(k, l), max(m, n)) <= 8) {
        if (abs(k - l) == abs(m - n)) {
            cout << "Может" << endl;
        }
        else {
            cout << "Не может" << endl;
        }
    }
    else {
        cout << "Ошибка ввода!" << endl;
    }

    // Вар 9
    int x, y, x1, y1, x2, y2;
    cout << "Введите координаты короля: " << endl; cin >> x >> y;
    cout << "Введите координаты ладьи: " << endl; cin >> x1 >> y1;
    cout << "Введите координаты слона: " << endl; cin >> x2 >> y2;
    if ((x == x1 || y == y1) && (abs(k - l) == abs(m - n))) {
        cout << "Угроза от ладьи И слона" << endl;
    }
    else if (x == x1 || y == y1) {
        cout << "Угроза от ладьи" << endl;
    }
    else if (abs(k - l) == abs(m - n)) {
        cout << "Угроза от слона" << endl;
    }
    else {
        cout << "Угрозы нет" << endl;
    }
    
    // Вар 3
    int k1, l1, m1, n1;
    cout << "Введите k, l " << endl; cin >> k1 >> l1;
    cout << "Введите m, n " << endl; cin >> m1 >> n1;
    if (k1 == m1 || l1 == m1 || abs(k1 - l1) == abs(m1 - n1)) {
        cout << "Можно попасть за 1 ход";
    }
    else{
        cout << "Нельзя попасть за 1 ход. За 2 хода можно попасть например так: ";
        cout << "Ходим на "; cout << m1 << " " << l1 << endl;
        cout << "Ходим на "; cout << m1 << " " << n1 << endl;
    }
}
