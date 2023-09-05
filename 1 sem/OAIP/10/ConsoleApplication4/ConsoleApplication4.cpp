#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int A, B, n, p, m, q, maskA, maskB = 0 , r;
    char tmp[33];
    cout << "Число А = "; cin >> A;
    _itoa_s(A, tmp, 2); cout << "A= " << tmp << "\n";
    cout << "Сколько битов инвертировать? "; cin >> n;
    cout << "С какой позиции? "; cin >> p;
    maskA = (1 << n) - 1;
    maskA <<= (p - 1);
    _itoa_s(maskA, tmp, 2); cout << "Маска для A " << tmp << "\n";
    _itoa_s(A ^ maskA, tmp, 2);
    cout << "Результат числа А: " << tmp;
    cout << "\n\n---------------------------------------------\n\n";
    maskA = 0;
    for (int i = 0; i < n; i++)
    {
        maskA += pow(2, i);
    }
    maskA <<= p - 1;
    cout << "Число B = "; cin >> B;
    _itoa_s(B, tmp, 2); cout << "B= " << tmp << "\n";
    cout << "Сколько битов? "; cin >> m;
    cout << "С какой позиции? "; cin >> q;

    for (int i = 0; i < n; i++)
    {
        maskB += pow(2, i);
    }
    maskB <<= q -1;
    maskB = ~maskB;
    _itoa_s(maskA, tmp, 2);
    cout << "Маска для А: " << tmp << endl;
    _itoa_s(A & maskA, tmp, 2);
    cout << "Выделенные биты А: " << tmp << endl;
    _itoa_s(maskB, tmp, 2);
    cout << "Маска для В: " << tmp << endl;
    _itoa_s(B & maskB, tmp, 2);
    cout << "Очищены биты в B: " << tmp << endl;
    r = p - q;
    if (r > 0)
        _itoa_s(((B & maskB) | ((A & maskA) >> r)), tmp, 2);
    else
        if (r < 0)
            _itoa_s(((B & maskB) | ((A & maskA) << (-r))), tmp, 2);
        else
            _itoa_s(((B & maskB) | (A & maskA)), tmp, 2);
    cout << "Результат B= " << tmp << endl;
}