
#include <iomanip> 
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';
	printf("Введите символ ");
	scanf_s("%c", &c);

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

	// Вар 7

	cout << "Вариант 7" << endl;
	cout << "Введите символ "; cin >> c;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;
	cout << setw(32) << setfill(probel) << probel;
	cout << setw(16) << setfill(c) << c << endl;

	// Вар 11
	cout << "Вариант 11" << endl;
	cout << "Введите символ "; cin >> c;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;

	// Вар 3
	cout << "Введите символ" << endl; 
	cin >> c;
	cout << setw(50) << setfill(probel) << c << endl;
	cout << setw(48) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(47) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(50) << setfill(probel) << c << endl;
	cout << setw(48) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(47) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(46) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(45) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;
	cout << setw(44) << setfill(probel) << probel;
	cout << setw(11) << setfill(c) << c << endl;
	cout << setw(50) << setfill(probel) << c << endl; 
	cout << setw(48) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(47) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(46) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(45) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;
	cout << setw(44) << setfill(probel) << probel;
	cout << setw(11) << setfill(c) << c << endl;
	cout << setw(43) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;
	cout << setw(42) << setfill(probel) << probel;
	cout << setw(15) << setfill(c) << c << endl;
	cout << setw(50) << setfill(probel) << c << endl;
	cout << setw(50) << setfill(probel) << c << endl;
	cout << setw(50) << setfill(probel) << c << endl;
	cout << setw(50) << setfill(probel) << c << endl;

}

