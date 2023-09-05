#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	// Вар 1
	int a, i = 0, num, sum = 0, x, y = 0;
	for (a = 100006; a <= 999999; a++) {
		int b = a;
		while (i < 6) {
			num = a % 10;
			a /= 10;
			sum += num;
			i++;
		}
		a = b;
		if (sum % 7 == 0 && sum != 0) {
			y++;
		}
		else {
			y = 0;
		}
		if (y == 2) {
			cout << a - 1 << endl << a;
			break;
		}
		sum = 0;
		i = 0;
	}



	// Вар 4
	int n;
	cout << "Введите n = ";
	cin >> n;
	double price = 0;
	double p; cout << "Введите p = "; cin >> p;
	while (n > 0) {
		double s;
		cin >> s;
		price += s - (s / 100) * pow(p, n);
		n--;
	}
	cout << "Итого: " << price;
	return 0;
}