#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, maskA = 3, x = 0;5
	cout << "A=";
	cin >> A;
	_itoa_s(~A, tmp, 2);

	if (tmp[31] == '0')
	{
		x = 1;
	}
	if (tmp[30] == '0')
	{
		x = 1;
	}
	if (x == 0)
	{
		cout << "кратно 4";
	}
	else
	{
		cout << "не кратно 4";
	}
}