#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

extern float balance;
extern float chance;

inline void setup() {

	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	system("cls");

	cout << "1) Пополнить баланс " << endl;
	cout << "2) Изменить цвет текста " << endl;
	cout << "3) Админ-панель " << endl;
	cout << "Код сессии: " << 1 + rand() % 10000 << endl;


	int decision; cin >> decision;
	system("cls");
	switch (decision) {
		case(1): {
			string num, cnn, srok;
			int sum;
			cout << "Введите номер карты: ";
			cin >> num;
			cout << "Введите CNN: ";
			cin >> cnn;

			cout << "Введите сумму пополнения: ";
			cin >> sum;

			balance += sum;
			system("cls");
			cout << "Выполняется Транзакция. Ожидайте!";
			this_thread::sleep_for(std::chrono::milliseconds(3000)); //sleep for 1 second
			system("cls");
			cout << "Транзакция завершена успешно! \n Перенаправление через 2 секунды...";
			this_thread::sleep_for(std::chrono::milliseconds(2000));
			break;
		}
		case(2): {
			cout << "Выберите цвет: \n 1 - желтый \n 2 - зеленый \n 3 - голубой \n";
			cin >> decision;
			switch (decision) {
				case(1): {
					system("color 6");
					break;
				}
				case(2): {
					system("color 2");
					break;
				}
				case(3): {
					system("color 3");
					break;
				}
			}
			break;
		}
		case(3): {
			cout << "1) Изменить баланс " << endl;
			cout << "2) Изменить шансы в казино " << endl;
			cin >> decision;
			switch (decision) {
				case(1): {
					cout << "Текущий баланс: " << balance << endl;
					cout << "Введите новое значение: " << endl;
					cin >> balance;
					break;
				}
				case(2): {
					
					cout << "Введите желаемый процент на победу ";
					cin >> chance;
					chance *= 100;
				}
			}
			break;

		}
		default: {
			break;
		}
	
	}

}