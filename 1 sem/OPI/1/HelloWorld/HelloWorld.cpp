#include <iostream>
using namespace std;
int k;
void a(int k);

void b(int g) {
    if (g > 3) {
        cout << "The end";

    }
    else {
        g++;
        a(g);
    }

}

void a(int k) {
    k++;
    b(k);
}


int main()
{
    a(0);
    return 0;
}
