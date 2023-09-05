#include "iostream";
#include "cmath"
using namespace std;

int main2() {
	double  a, b, m;
	cin >> m;
	b = (-5 + sqrt(25 + 4 * m)) / 2;
	a = m / b;
	cout << "b = " << b << "; a = " << a << endl;
	return 0;
}