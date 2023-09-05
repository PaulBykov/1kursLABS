#include <ctime>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int n, ** A, m;
	cout << "Введите n, m ";
	cin >> n >> m;

	A = new int* [n];    //выделение динам.памяти
	int MAX = -100000;
	int cord[2] = {};

	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
		for (int j = 0; j < m; j++) {
			A[i][j] = 1 + rand() % 10;
			cout << A[i][j] << " ";
			if (A[i][j] > MAX) {
				MAX = A[i][j];
				cord[0] = i;
				cord[1] = j;
			}

		}
		cout << endl;
	}


	for (int i = n - 1; i >= 0; i--) {
		if (A[i] < 0) {
			cout << i;
			break;
		}
	}

	cout << "MAX = " << MAX << endl << endl;

	swap(A[0], A[cord[0]]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int j = 0; j < n; j++) {
		swap(A[j][0], A[j][cord[1]]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
