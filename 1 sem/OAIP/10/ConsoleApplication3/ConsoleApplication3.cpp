#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, maskA, r, i = 0;
	cout << "Целое число="; cin >> A;
	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	r = A;
	while (r > 0)
	{
		r /= 2;
		i++;
	}
	maskA = ((1 << i-1)) - 1 << 1;
	_itoa_s(maskA, tmp, 2);
	cout << "Маска для А: " << tmp << endl;
	_itoa_s((A ^ maskA), tmp, 2);
	cout << " Результат A=" << tmp << endl;
}