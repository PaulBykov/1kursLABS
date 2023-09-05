#include <iostream>

using namespace std;

int getSum(int a, int b) {
    return a + b;
}

int getMul(int a, int b) {
    return a * b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b) << " " << getMul(a, b);

}
