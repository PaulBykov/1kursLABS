#include <iostream>
#include <vector>
#include <algorithm>

int getFive() {
    return 5;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int target1 = 3;

    int num_items1 = count(v.begin(), v.end(), target1);

    std::cout << "Число: " << target1 << " количество: " << num_items1 << std::endl;

    int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });

    std::cout << "Количество элементов, кратных 3: " << num_items3 << std::endl << std::endl;

    std::cout << "Лямбда, захват переменных" << std::endl;

    for (auto i : v) [i]()
    {
        if (i % 3 == 0)
            std::cout << i << " ";
    }();

    std::cout << "\nЛямбда с параметрами" << std::endl;
    for (auto i : v) [](auto i)
    {
        if (i % 3 == 0)
            std::cout << i << " ";
    }(i);

    std::cout << "\nЛямбда без параметров" << std::endl;
    for (auto i : v) [i]()
    {
        if (i % 3 == 0)
            std::cout << i << " ";
    }();

    std::cout << "\nДополнительно: " << std::endl;
    int b;
    std::cin >> b;

    auto result = [](auto a)
    {
        return a > 0;
    }(b);

    std::cout << result << std::endl;

    std::cout << getFive();

}
