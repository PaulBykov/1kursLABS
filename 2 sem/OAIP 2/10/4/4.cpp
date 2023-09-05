#include <iostream>
#include <cmath>

using namespace std;

int i = 0;

int numsq(int a, int b) {
    i++;
    if (!b) {
        return 0;
    }
    return floor(a/b) + numsq(b, a % b);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int a, b;

    cout << "Введите a, b: ";
    cin >> a >> b;

    numsq(a, b);

    cout << "Кол-во квадратов = " << i << endl;


    return 0;
}

