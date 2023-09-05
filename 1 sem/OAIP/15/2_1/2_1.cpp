#include <ctime>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int n,  *A;
	cout << "Введите n ";
	cin >> n;
	srand(time(0));
	if (!(A = (int*)malloc(n * sizeof(int))))   //выделение памяти и проверка, 
	{	                                        //достаточно ли для нее места
		puts("Not enough memory");
		return 0;
	}

	bool is_negativ = false;

	cout << "Введите массив A: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] < 0) {
			is_negativ = true;
		}
	}

	if (!is_negativ) {
		cout << "Отрицательных чисел нет" << endl;
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			if (A[i] < 0) {
				cout << i;
				break;
			}
		}
	}

	free(A);

	return 0;
}
