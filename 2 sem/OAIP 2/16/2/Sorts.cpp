#include <iostream>

using std::cout;
using std::cin;
using std::endl;

inline void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

inline void printBackwordArray(int* A, int n) {
    for (int i = n - 1; i > -1; i--) {
        cout << A[i] << " ";
    }
    cout << endl;
}


inline void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Перебираем все элементы массива
    for (i = 0; i < n - 1; i++) {
        // Находим наименьший элемент в оставшейся части массива
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Меняем найденный минимальный элемент с текущим
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


inline void quickSort(int* A, int left, int right) {
    if (left < right) {
        int pivot = A[(left + right) / 2]; // выбираем опорный элемент
        int i = left - 1;
        int j = right + 1;
        while (true) {
            do {
                i++;
            } while (A[i] < pivot);
            do {
                j--;
            } while (A[j] > pivot);
            if (i >= j) {
                break;
            }
            std::swap(A[i], A[j]);
        }
        quickSort(A, left, j);
        quickSort(A, j + 1, right);
    }
}

inline void bubbleSort(int arr[], int n) {
    bool swapped = true;
    int j = 0;
    int tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}


inline void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

inline int shuffle(int A[], int*& B, int n, int choice) {
    int lastIndex = 0;

    switch (choice) {
    case 1: {
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                B[lastIndex] = A[i];
                lastIndex++;
            }
        }


        break;
    }

    case 2: {
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0 && A[i + 1] % 2 != 0) {
                B[lastIndex] = A[i];
                lastIndex++;
            }
        }
        break;
    }
    case 6: {
        for (int i = 0; i < n - 1; i++) {
            if (A[i] % 2 == 0) {
                B[lastIndex] = A[i];
                lastIndex++;
            }
        }
        break;
    }
    case 9: {
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0 && A[i + 1] % 2 != 0) {
                B[lastIndex] = A[i];
                lastIndex++;
            }
        }
        break;
    }
    default:
        cout << "Ошибка ввода!" << endl;
        delete[] B; // освобождение памяти в случае ошибки
        return 0;
    }

    int m = lastIndex;

    if (!m) {
        cout << "Длина B = 0" << endl;
        delete[] B;
        return 0;
    }

    // уменьшение размера массива до m
    int* newB = new int[m];
    for (int i = 0; i < m; i++) {
        newB[i] = B[i];
    }

    delete[] B; // освобождение памяти старого массива
    B = newB;

    return m;
}

inline void shellSort(int arr[], int n) {
    // Определение интервала начального прохода
    int interval = 1;
    while (interval <= n / 3) {
        interval = interval * 3 + 1;
    }

    while (interval > 0) {
        // Сортировка подмассивов вставкой с заданным интервалом
        for (int i = interval; i < n; i++) {
            int tmp = arr[i];
            int j = i;

            while (j > interval - 1 && arr[j - interval] >= tmp) {
                arr[j] = arr[j - interval];
                j -= interval;
            }

            arr[j] = tmp;
        }

        interval = (interval - 1) / 3;
    }
}

inline void heapify(int A[], int pos, int n)
{
    int t, tm;
    while (2 * pos + 1 < n)
    {
        t = 2 * pos + 1;
        if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
            t = 2 * pos + 2;
        if (A[pos] < A[t])
        {
            tm = A[pos];
            A[pos] = A[t];
            A[t] = tm;
            pos = t;
        }
        else break;
    }
}

inline void piramSort(int A[], int n)
{
    for (int i = n - 1; i >= 0; i--)
        heapify(A, i, n);
    while (n > 0)
    {
        int tm = A[0];
        A[0] = A[n - 1];
        A[n - 1] = tm;
        n--;
        heapify(A, 0, n);
    }
}
