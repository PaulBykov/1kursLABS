#include <cstdlib>
#include <ctime>
#include "Sorts.cpp"



using namespace std;



int main() {
    setlocale(LC_ALL, "Rus");

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int choice1;
    cout << "Выберите вариант (1, 2, 6, 9)" << endl;
    cin >> choice1;



    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Создаем массив А и заполняем его случайными числами от 1 до 1000
    int* A = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 1000 + 1;
    }

    int* B = new int[n];
    

    int m = shuffle(A, B, n, choice1);

    cout << "Исходный массив A: ";
    printArray(A, n);
    cout << "\n\n";

    cout << "Исходный массив B: ";
    printArray(B, m);
    cout << "\n\n";

    int choice = 0;

    while (choice != 6) {

        cout << "Выберите способ сортировки массива B:\n";
        cout << "1. Сортировка выбором\n";
        cout << "2. Быстрая сортировка\n";
        cout << "3. Сортировка вставками\n";
        cout << "4. Сортировка пузырьком\n";
        cout << "5. Сортировка Шелла\n";
        cout << "6. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;


        double start = clock();
        double end = clock();

        int m = shuffle(A, B, n, choice1);

        switch (choice) {
            case 1: {

                start = clock();

                selectionSort(B, m);

                end = clock();

                cout << "Отсортированный массив B (сортировка выбором): ";
                printBackwordArray(B, m);

                cout << "Время выполнения: " << ((end - start) / CLOCKS_PER_SEC) * 1e3 << " мс\n";
            
                break;
            }
            case 2: {
                start = clock();

                quickSort(B, 0, m - 1);

                end = clock();

                cout << "Отсортированный массив B (быстрая сортировка): ";
                printBackwordArray(B, m);

                cout << "Время выполнения: " << ((end - start) / CLOCKS_PER_SEC) * 1e3 << " мс\n";

                break;
            case 3:
                start = clock();

                insertionSort(B, m);

                end = clock();

                cout << "Отсортированный массив B (сортировка вставками): ";
                printBackwordArray(B, m);

                cout << "Время выполнения: " << ((end - start) / CLOCKS_PER_SEC) * 1e3 << " мс\n";

                break;
            case 4:
                start = clock();

                bubbleSort(B, m);

                end = clock();

                cout << "Отсортированный массив B (сортировка пузырьком): ";
                printBackwordArray(B, m);

                cout << "Время выполнения: " << ((end - start) / CLOCKS_PER_SEC) * 1e3 << " мс\n";

                break;
            case 5:
                start = clock();

                shellSort(B, m);

                end = clock();

                cout << "Отсортированный массив B (сортировка Шелла): ";
                printArray(B, m);

                cout << "Время выполнения: " << ((end - start) / CLOCKS_PER_SEC) * 1e3 << " мс\n";

                break;
            case 6:
                return 0;
                break;
            default:
                cout << "Ошибка: неправильный выбор!\n";
                return 0;
                break;
            }

        }


    }


    delete[] A;
    delete[] B;

    return 0;
}
