#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
		char tmp[33];
		char tmp1[33];
		int A, n, m, p, num;
	cout << "Число А = ", cin >> A;
	cout << "Введите количество битов, которое нужно установить в ноль ", cin >> n;
	cout << "Введите номер позиции с которой они должены стоять ", cin >> m;
	_itoa_s(A, tmp1, 2);
	cout << tmp1 << endl;
	p = m - n;
	int maskA = pow(2, n) - 1;
	int maskAB = maskA * pow(2, p); // все тоже самое что и сверху, но для маски B
	int maskB = ~maskAB; // сама маска  В с перевернутыми значениями 

	_itoa_s(((A & maskB) | (maskA >> n)), tmp, 2);
	cout << " Результат B=" << tmp << endl;

	return 0;
}
