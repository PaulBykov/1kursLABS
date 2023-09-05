#include <iostream>
#include <iomanip>

#define n 2;

using namespace std;

constexpr int GiveFive() { return 5; }



int main()
{
	setlocale(LC_ALL, "Rus");

	int x, y, z;
	double S;
	x = 9 + n;
	y = 10 + n;
	z = 11 + n;
	S = 1.0 + n;

	bool TRUE = true, FALSE = false;


	char lat = 'u';
	char rus = 'ы';
	wchar_t wlat = 'B';
	wchar_t wrus = 'Б';

	short nine = x, nine1 = -x;

	cout << "X16 = " << hex << nine << endl;
	cout << "-X16 = " << hex << nine1 << endl;

	short smax = SHRT_MAX;
	short smin = SHRT_MIN;
	unsigned short usmax = USHRT_MAX;
	unsigned short usmin = 0;

	int six = y, six1 = -y;
	cout << "Y16 = " << hex << six << endl;
	cout << "-Y16 = " << hex << six1 << endl;


	int imax = INT_MAX;
	int imin = INT_MIN;
	unsigned int ismax = UINT_MAX;
	unsigned int ismin = 0;
	
	int ten = z, ten1 = -z;
	cout << "imax = " << hex << imax << endl;
	cout << "imax = " << hex << imin << endl;
	cout << "Z16 = " << hex << ten << endl;
	cout << "-Z16 = " << hex << ten1 << endl;

	long lmax = LONG_MAX;
	long lmin = LONG_MIN;
	unsigned long lsmax = ULONG_MAX;
	unsigned long lsmin = 0;


	float two = S, two1 = -S;

	cout << "S16 = " << hex << setprecision(3) << two << endl;
	cout << "-S16 = " << hex << two1 << endl;

	double pd1 = 10.124;


	char* pch = &rus; wchar_t* pwch = &wlat; short* ps = &nine; int* pi = &ten; float* pf=&two; double* pd = &pd1;
	pch += 3; pwch += 3; ps += 3; pi += 3; pf += 3; pd += 3;

	int (*toFive)();
	toFive = GiveFive;

	cout << "Дай пять - " << toFive() << endl;


	float var1 = INFINITY;
	float var2 = -INFINITY;
	float var3 = NAN;

	cout << var1 << " " << var2 << " " << var3 << endl;

	return 0;
}
