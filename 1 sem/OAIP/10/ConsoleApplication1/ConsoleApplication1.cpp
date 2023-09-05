#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, B, n, p, m, q, maskA, maskB;
	char tmp[33];
	cout << "Число А = "; cin >> A;
	_itoa_s(A, tmp, 2); cout << "A= " << tmp << "\n";
	cout << "Сколько битов установить в 1? "; cin >> n;
	cout << "С какой позиции? "; cin >> p;
	maskA = (1 << n) - 1;
	maskA <<= (p - n);
	_itoa_s(maskA, tmp, 2); cout << "Маска для A " << tmp << "\n";
	_itoa_s(A | maskA, tmp, 2);
	cout << "Результат числа А: " << tmp;
}