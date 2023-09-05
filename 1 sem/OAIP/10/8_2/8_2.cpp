#include <iostream>
#include <bitset>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	char tmp[33];
	int A, B, n, m;
	cout << "Число А= ", cin >> A;
	cout << "Число В= ", cin >> B;
	cout << "Введите позицию с которой должены браться биты: ", cin >> n;
	cout << "Введите позицию в которую должены добавляться биты: ", cin >> m;
	n--; m--;
	int maskA = 7 * pow(2, n); // для смещения маски 7 - 111 в двоичной с/с, 7 * 2^n, 2^n количество нулей после 111, чтобы сдвинуть маску 
	int maskAB = 7 * pow(2, m); // все тоже самое что и сверху, но для маски B
	int maskB = ~maskAB; // сама маска  В с перевернутыми значениями 
	_itoa_s(A, tmp, 2);
	cout << "A= " << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "B= " << tmp << endl;
	_itoa_s((A & maskA) >> n, tmp, 2);
	cout << "Выделенные биты А: " << tmp << endl;
	_itoa_s(((B & maskB) | ((A & maskA) >> n) << m), tmp, 2);
	cout << "Результат B= " << tmp << endl;

	return 0;
}
