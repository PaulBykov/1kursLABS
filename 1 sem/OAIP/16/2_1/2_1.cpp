#include <iostream>
#include <stdio.h>
#include <locale>
#include <windows.h>
#include <cctype> 

using namespace std;

void task1(double **A, int n, int m) {
	setlocale(LC_ALL, "Rus");

	cout << "\nИзмененный массив: " << endl;

	for (int i = 0; i < n; i++) {
		if (*(*(A + i) + 0) != 0) {
			for (int j = 0; j < m; j++) {
				*(*(A + i) + j) += 1;
			}
		}
		for (int j = 0; j < m; j++) {
			cout << *(*(A + i) + j) << " ";
		}
		cout << endl;
	}


}

void task2(char *A) {
	for (int i = 0; i < strlen(A); i++) {
		if (isalpha(A[i])) {
			A[i] = '?';
			cout << A[i];
		}
		else if((int)A[i] >= (int)'А' && (int)A[i] <= (int)'я') {
			char character = A[i];
			A[i] = (char)toupper(character);
			cout << A[i];
		}
		else {
			cout << A[i];
		}

	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	cout << "Введите номер подзадачи (1 или 2): " << endl;
	cin >> k;
	switch (k) {
		case(1): {
			int n, m;
			double** A;
			cout << "Введите n (кол-во строк) ";
			cin >> n;
			cout << "Введите m (кол-во столбцов) ";
			cin >> m;

			A = new double* [n];    //выделение динам.памяти
			for (int i = 0; i < n; i++) {
				A[i] = new double[n];
				for (int j = 0; j < m; j++) {
					cin >> A[i][j];
				}
			}
			task1(A, n, m);
			break;
		}
		case(2): {
			locale rus("russian");
			locale::global(rus);
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			setlocale(LC_CTYPE, "1251");
			setlocale(LC_ALL, "Rus");

			char A[255];
			cout << "Введите предложение: " << endl;
			bool state = ios::sync_with_stdio(false);
			cin.ignore(cin.rdbuf()->in_avail());
			ios::sync_with_stdio(state);
			cin.getline(A, 255);
			task2(A);
			break;
		}
		default: {
			cout << "Ошибка ввода!";
		}
	}


	return 0;
}
