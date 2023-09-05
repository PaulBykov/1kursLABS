#include <iostream>
#include <vector>


using namespace std;
int main()
{
	// Вар 1
	setlocale(LC_ALL, "Rus");
	int a, i = 0, num, sum = 0, x, y = 0;
	for (a = 100000; a <= 999999; a++) {
		int b = a;	
		while (i < 6) {
			num = a % 10;
			a /= 10;
			sum += num;
			i++;
		}
		a = b;
		if (sum % 7 == 0) {
			y++;
		}
		else {
			y = 0;
		}
		if (y == 2) {
			cout << a - 1 << endl << a << endl;
		}
		sum = 0;
		i = 0;
	}



	// Вар 4
	int n;
	cout << "Введите n = ";
	cin >> n;	
	double price = 0;
	double p; cout << "Введите p = "; cin >> p; p /= 100;
	i = 0;
	vector<double> s(n);
	while (i < n) {
		cin >> s[i];
		i++;
	}
	i = 0;
	while (i < n) {
		s[i] = s[i] - s[i] * p;
		price += s[i];
		i++;
	}
	cout << "Итого: " << price << endl;



    // Вар 2
    int p1, q, days = 1;
    double sum1 = 0;
    cout << "Введите p = ";
    cin >> p1;
    cout << "Введите q = ";
    cin >> q;
    while (p1 < q) {
        p1 *= 1.03;
        days ++;
    }

    cout << "Выручка в последний день: " << p1 << endl;
    cout << "Количество дней: " << days;

}
