#include <locale>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите размер массива" << endl;
	cin >> n;
	// cout << "Введите элементы массива: " << endl;

	const int maxSize = 100;
	int i, a[maxSize] = {}, kmax = 0;
	int L[maxSize] = {}, m[maxSize] = {};
	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
		cout << a[i] << " ";
	}

	// Вар 2

	cout << endl;
	int MAX = 0, MIN = 100;
	int max_index = 0, min_index = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] > MAX) {
			MAX = a[i];
			max_index = i;
		}
		if (a[i] < MIN) {
			MIN = a[i];
			min_index = i;
		}
	}

	if (max_index < min_index) {
		swap(max_index, min_index);
	}
	for (int i = 0; i <= min_index; i++) {
		cout << a[i] << " ";
	}

	for (int i = max_index - 1; i > min_index; i--) {
		cout << a[i] << " ";
	}

	for (int i = max_index; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << endl;	

	// Вар 3
	int k = 0;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] == a[i + 1] || a[i] == a[i - 1]) {
			k++;
			i++;
		}
	}

	cout << " Кол-во пар соседних равных элементов: " << k << endl;


	// вар 5
	int j = 0;
	int b[maxSize]{};
	for (int i = 0; i < n; i++) {
		b[ a[i] - 1] ++;
	}

	for (int i = 0; i < maxSize; i++) {
		if (b[i] != 0) {
			j++;
		}
	}

	cout << "Кол-во различных элементов: " << j;

	return 0;
}
