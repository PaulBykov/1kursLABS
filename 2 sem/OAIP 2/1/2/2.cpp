
#include <iostream>

using namespace std;

int fsum(int n, ...) {

    int* p = &n;
    int sum = 0;
    p += 2;
    for (int i = 0; i < n - 1; i++) {
        int x = *p;
        p += 2;
        int y = *p;
        sum += x * y;
    }

    return sum;
}

int main()
{

    cout << fsum(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;
    cout << fsum(3, 1, 2, 3) << endl;
    cout << fsum(5, 1, 2, 3, 4, 5) << endl;
    return 0;
}

