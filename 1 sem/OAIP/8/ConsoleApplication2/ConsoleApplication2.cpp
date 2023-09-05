#include <locale>
#include <iostream> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int maxSize = 10000;
	int n, i, a[maxSize], kmax = 0;
	int L[maxSize] = {}, m[maxSize] = {};
	cout << "Введите размер массива" << endl;
	cin >> n;

	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
		cout << a[i] << " ";
	}


	cout << endl;
	int L_len = 0;
	for (i = 0; i < n; i++)
		if (a[i] % 2 == 0) {
			L[i] = a[i];
		}
		else {
			m[i] = a[i];
		}

	cout << endl << "L(n): " << " ";

	for (int i = 1; i < n; i++) {
		if (L[i] != 0) {
			L_len++;
			cout << L[i] << " ";
		}
	}

	cout << endl << "Длинна L(n) = " << L_len << endl;

	cout << endl;

	cout << "m(n): " << " ";

	for (int i = 1; i < n; i++) {
		if (m[i] != 0) {
			cout << m[i] << " ";
		}
	}

	cout << endl << "Длинна m(n) = " << n - L_len << endl;

	return 0;
}
