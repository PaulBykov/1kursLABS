#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, n, p, B;
	char tmp[33];
	cout << "Введите число ";
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "Число в двоичном виде = " << tmp << endl;
	cout << "Введите позицию: ";
	cin >> p;
	cout << "Ведите количиство битов: ";
	cin >> n;
	B = (1 << n) - 1;
	B <<= p - 1;
	_itoa_s(A | B, tmp, 2);
	cout << "Результат = " << tmp << endl;
}