#include "iostream";
#include "cmath";
using namespace std;

int main() {
	double  a, b, m;
	cout << "m = "; cin >> m;
	b = (m - 5) / 2;
	a = m - b;
	if (b > a) {
		swap(a, b);
	}
	cout <<  b << " " << a << endl;

	// Вариант 7
	double c, s;
	double pi = 3.14159265358979323846;
	cout << "c = "; cin >> c;
	cout << "S = " << c * c / (4 * pi) << endl;

	// Вариант 11
	double d;
	cout << "d = "; cin >> d;
	cout << "S = " << d * d / 2 << endl;

	// Вариант 3
	double n, h, osn;
	cout << "n = ";
	cin >> n;
	if (n == 0) {
		cout << "S = " << 0;
	}
	else {
	h = (2 + 2 * n) / n;
		osn = h * n;
		cout << "S = " << h * osn;
	}


	return 0;
}

