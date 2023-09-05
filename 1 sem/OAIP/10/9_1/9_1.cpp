#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char tmp[33];
	int A, B, n = 2, m = 1;
	cout << "Число А= ", cin >> A;
	cout << "Число В= ", cin >> B;
	int maskA = 31 * pow(2, n); // для смещения маски 31 - 11111 в двоичной с/с, 31 * 2^n, 2^n количество нулей после 111, чтобы сдвинуть маску 
	int maskAB = 31 * pow(2, m); // все тоже самое что и сверху, но для маски B
	int maskB = ~maskAB; // сама маска  В с перевернутыми значениями 
	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;
	_itoa_s((A & maskA) >> n, tmp, 2);
	cout << "Выделенные биты А: " << tmp << endl;
	_itoa_s(((B & maskB) | ((A & maskA) >> n) << m), tmp, 2);
	cout << " Результат B=" << tmp << endl;
}
