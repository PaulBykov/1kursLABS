
#include <iomanip> 
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';
	cout << "Введите символ "; cin >> c;
	cout << setw(40) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(40) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
}

