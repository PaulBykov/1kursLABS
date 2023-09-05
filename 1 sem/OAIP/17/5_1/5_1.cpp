#include <iostream>

using namespace std;

int summ(int*, int*);

int main()
{
	int* A, sum = 0;
	setlocale(LC_ALL, "Rus");
	A = new int[15];
	cout << "Введите значение элементов в массиве\n";
	for (int i = 0; i < 15; i++)
	{
		cin >> A[i];
	}
	cout << " Сумма чётных элементов: " << summ(A, &sum);
}

int summ(int* pA, int *sum)
{
	for (int i = 0; i < 15; i++)
		if (pA[i] % 2 == 0)
			*sum += pA[i];
	return *sum;
}


