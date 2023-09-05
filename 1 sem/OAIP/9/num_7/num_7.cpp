#include <locale>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int maxSize = 99;
	int n, i, a[maxSize], kmax = 0;
	int L[maxSize] = {}, m[maxSize] = {};
	cout << "Введите размер массива (не более 99)" << endl;
	cin >> n;

	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 99;
		cout << a[i] << " ";
	}


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

	swap(a[max_index], a[min_index]);

	cout << "Result: " << " ";

	for (int i = 0; i < n; i++) {

		cout << a[i] << " ";


	}



	return 0;
}
