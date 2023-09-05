
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int ans;
	cout << "Ты любишь шахматы? (1 - да; 2 - нет)" << endl;
	cin >> ans;
	switch (ans) {
		case(1): {
			cout << "Какой вариант сицилианской защиты предпочитаешь? \n 1 - Закрытая \n 2 - открытая \n 3 - Вариант дракона" << endl;
			cin >> ans;
			switch (ans) {
				case(1): cout << "Солидно"; break;
				case(2): cout << "Не солидно"; break;
				case(3): cout << "КРУТОЙ!!!"; break;
			}
		}; break;
		case(2): cout << "Ответ неверный"; break;
		default: cout << "Ошибка ввода!"; break;
	}


}
