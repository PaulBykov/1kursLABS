#include <iostream>
#include <ctime>

using namespace std;


unsigned long long linear_fib(int n) {
    int prev = 0, current = 1;
    if (n == 1) { // т.к current = 1 по умолчанию, отдельного исключения для n = 1 не требуется
        return 0;
    }
    for (int i = 2; i < n; i++) {
        current += prev;
        prev = current - prev;
    }
    return current;

}


unsigned long long recursive_fib(int n) {
    return n <= 1 ? n : recursive_fib(n - 1) + recursive_fib(n - 2); // если n <= 1, то вернуть n, иначе сумму двух предыдущих
}


int main()
{
    
    setlocale(LC_ALL, "Rus");

    int decision;
    cout << "Выберите способ:\n 1 - линейный \n 2 - рекурсивный" << endl;
    cin >> decision;

    switch (decision) {
        case(1): {
            int n; // номер числа Фибоначчи
            cout << "Введите значение n" << endl;
            cin >> n;
            double startTime = clock();
            cout << "Значение числа Фибоначчи № " << n << " = " << linear_fib(n) << endl;
            double endTime = clock();
            double resultTime = (endTime - startTime) / CLOCKS_PER_SEC;
            cout << "Расчетное время циклом " << int(resultTime) / 60 << " минут " << int(resultTime) % 60 << " секунд" << endl;
            break;
        }
        case(2): {
            int n;
            cout << "Введите значение n" << endl;
            cin >> n;
            double startTime = clock();
            cout << "Значение числа Фибоначчи № " << n << " = " << recursive_fib(n-1) << endl;
            double endTime = clock();
            double resultTime = (endTime - startTime) / CLOCKS_PER_SEC;
            cout << "Расчетное время рекурсией " << int(resultTime) / 60 << " минут " << int(resultTime) % 60 << " секунд" << endl;
            break;
        }
        default: {
            cout << "Ошибка ввода!";
        }
    }

    return 0;
}


