#include <iostream>
using namespace std;
int main()
{
	int k;
	setlocale(LC_ALL, "Rus");
	cout << "Вы выпили кофе" << endl;
	cout << "Недомогание есть? 1 - да, 2 - нет" << endl;
	cin >> k;
	if (k == 1) {
		cout << "Сильное? 1 - да, 2 - нет" << endl;
		cin >> k;
		if (k == 1) {
			cout << "Вы выпили кофе";
			cout << "Легче? 1 - да, 2 - нет" << endl;
			cin >> k;
			if (k == 1) {
				cout << "Вы сделали грустное лицо" << endl;
				cout << "Вы пошли на пары" << endl;
				cout << "КОНЕЦ";
			}
			else {
				cout << "Вы остались дома" << endl;
				cout << "Вы следите за своим состоянием" << endl;
				cout << "СПАТЬ \n КОНЕЦ";
			}
		}
		else {
			cout << "Вы сделали грустное лицо" << endl;
			cout << "Вы пошли на пары" << endl;
			cout << "КОНЕЦ";
		}
	}
	else {
		cout << "КОНЕЦ";
	}
}
