#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void sortMethodPuz(int*, int); // Метод пузырька n^2 n
void sortMethodInsert(int*, int); // Метод вставки n^2 n
void sortMethodSelection(int*, int); // Метод выбора n^2 n^2
void quickSort(int* arr, int first, int last); // Быстрая сортировка n log n  n
void outArr(int*, int); // Вывод массивов

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size,
		start,
		end,
		timePuz,
		timeShella,
		timeSel,
		timeFast;

	cout << "Введите число элементов, которые будут в массиве: "; cin >> size;

	int* A = new int[size],
		* B = new int[size],
		* C = new int[size],
		* D = new int[size],
		* E = new int[size];

	cout << "Массив А(исходный) состоит из:\n";
	srand(time(NULL));
	for (int i = 0, num; i < size; i++)
	{
		num = rand() % 100;
		A[i] = B[i] = C[i] = D[i] = E[i] = num;
	}
	outArr(A, size);

	cout << "\n";

	cout << "Массив B(пузырек) состоит из:\n";
	start = clock();
	sortMethodPuz(B, size);
	end = clock();
	outArr(B, size);
	timePuz = end - start;

	cout << "\n";

	cout << "Массив С(вставка) состоит из:\n";
	start = clock();
	sortMethodInsert(C, size);
	end = clock();
	outArr(C, size);
	timeShella = end - start;

	cout << "\n";

	cout << "Массив D(выбором) состоит из:\n";
	start = clock();
	sortMethodSelection(D, size);
	end = clock();
	outArr(D, size);
	timeSel = end - start;

	cout << "\n";

	cout << "Массив E(быстрая) состоит из:\n";
	start = clock();
	quickSort(E, 0, size - 1);
	end = clock();
	outArr(E, size);
	timeFast = end - start;

	cout << "\n";

	cout << "Метод пузырька занял в " << timePuz << " мс\n"
		<< "Метод вставки занял в " << timeShella << " мс\n"
		<< "Метод выбором занял в " << timeSel << " мс\n"
		<< "Быстрый метод занял в " << timeFast << " мс\n";

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
}


//Процедуры

void outArr(int* arr, int N)
{
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void sortMethodPuz(int* arr, int N)
{
	int buff = 0; // для временного хранения значения, при перезаписи

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}

void sortMethodInsert(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // запомним обрабатываемый элемент arr[j]
	 // и начнем перемещение элементов слева от него
	 // пока запомненный не окажется меньше чем перемещаемый
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}

void sortMethodSelection(int* arr, int N)
{
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями 
	for (int i = 0; i < N; i++)
	{
		min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (arr[j] < arr[min]) ? j : min; // тернарный оператор условие ? если true : если false
		// Сделаем перестановку этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
void quickSort(int* arr, int first, int last)
{
	int mid, count;
	int f = first, l = last; // указатели на первый и последний элемент
	mid = arr[(f + l) / 2]; // вычисление опорного элемента
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l) // перестановка элементов
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l); // пока right не окажется слева от left
	if (first < l) quickSort(arr, first, l);
	if (f < last) quickSort(arr, f, last);
}