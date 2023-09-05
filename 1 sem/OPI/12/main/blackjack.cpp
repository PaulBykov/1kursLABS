#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <map>
#include <iomanip>

extern float balance;
extern float bet;

using namespace std;

inline void GetCard(int& hand, vector< vector<string> >& coloda, vector< vector<string> >& player, int& temp);


inline int GetSum(vector< vector<string> >& player) {
	int sum = 0;
	map<string, int> point; // дешифратор: величина карты = кол-во очков

	point["2"] = 2;
	point["3"] = 3;
	point["4"] = 4;
	point["5"] = 5;
	point["6"] = 6;
	point["7"] = 7;
	point["8"] = 8;
	point["9"] = 9;
	point["10"] = 10;
	point["J"] = 10;
	point["Q"] = 10;
	point["K"] = 10;
	point["A"] = 11;
	for (int i = 0; i < player.size(); i++) {
		
		sum += point[player[i][0]];

	}
	
	return sum;

}

inline void jack() {
	setlocale(LC_ALL, "Rus");
	const int n = 52;


	vector< vector<string> > coloda;
	coloda.resize(n, vector <string>(2));
	vector<string> cards = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	vector<string> mast = { "#", "$", "%", "&" }; //{ "♠", "♥", "♣", "♦" };

	vector< vector<string> > diller;
	diller.resize(11, vector <string>(2, "0"));

	srand((unsigned)time(NULL));
	int i = 0, j = 2;
	while(i < 52){ 
		coloda[i][0] = cards[i / 4]; // заполняю колоду цифрами
		coloda[i][1] = mast[i % 4]; // заполняю колоду мастямиы
		i++;
	}

	int temp = rand() % 52, hand_diller = 0;
	GetCard(hand_diller, coloda, diller, temp);
	GetCard(hand_diller, coloda, diller, temp);

	vector< vector<string> > player;
	player.resize(11, vector <string>(2, "0"));

	do { temp = rand() % 52; } while (coloda[temp][0] == "0");
	int hand = 0;
	GetCard(hand, coloda, player, temp);
	GetCard(hand, coloda, player, temp);
	
	tp:
	while (GetSum(player) < 21) {
		cout << "Ваши карты: " << endl;
		i = 0;
		while (player[i][0] != "0") {
			char symbol = '-', space = ' ';
			cout << " " << setw(9) << setfill(symbol) << symbol << endl;
			cout << "|";
			if (player[i][0] == "10") {
				cout << setw(5) << setfill(space) << space;
			}
			else {
				cout << setw(6) << setfill(space) << space;
			}
			cout << player[i][0] << " " << player[i][1] << "|" << endl;
			for (int j = 0; j < 6; j++) {
				cout << "|";
				cout << setw(9) << setfill(space) << space << "|" << endl;
			}
			cout << " " << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}
		cout << "Ваши очки: " << GetSum(player) << endl;
		cout << "Желаете взять ещё карту? (1 - да, 2 - нет)" << endl;
		int decision = 0;
		cin >> decision;
		system("cls");
		switch (decision) {
			case(1):{
				
				GetCard(hand, coloda, player, temp);
				goto tp;
				break;
			}
			default: {
				break;
			}
				   
		}
		break;
	}


	if (GetSum(player) <= 21) {
		cout << "Ваши карты: " << endl;
		i = 0;
		while (player[i][0] != "0") {
			char symbol = '-', space = ' ';
			cout << " " << setw(9) << setfill(symbol) << symbol << endl;
			cout << "|";
			if (player[i][0] == "10") {
				cout << setw(5) << setfill(space) << space;
			}
			else {
				cout << setw(6) << setfill(space) << space;
			}
			cout << player[i][0] << " " << player[i][1] << "|" << endl;
			for (int j = 0; j < 6; j++) {
				cout << "|";
				cout << setw(9) << setfill(space) << space << "|" << endl;
			}
			cout << " "  << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}
		cout << "Ваши очки: " << GetSum(player) << endl;
		while (GetSum(diller) <= 18 && GetSum(diller) < GetSum(player)) {
			GetCard(hand_diller, coloda, diller, temp);
		}

		cout << "Карты Диллера: " << endl;
		i = 0;
		while (diller[i][0] != "0") {
			char symbol = '-', space = ' ';
			cout << " " << setw(9) << setfill(symbol) << symbol << endl;
			cout << "|";
			if (player[i][0] == "10") {
				cout << setw(5) << setfill(space) << space;
			}
			else {
				cout << setw(6) << setfill(space) << space;
			}
			cout << diller[i][0] << " " << diller[i][1] << "|" << endl;
			for (int j = 0; j < 6; j++) {
				cout << "|";
				cout << setw(9) << setfill(space) << space << "|" << endl;
			}
			cout << " " << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}

		cout << "Сумма диллера: " << GetSum(diller) << endl;


		if (GetSum(diller) > GetSum(player) && GetSum(diller) < 22) {
			cout << "Победа диллера!" << endl;
			balance -= bet;
		}
		else if (GetSum(diller) == GetSum(player) && GetSum(diller) < 22) {
			cout << "Ничья!" << endl;
		}
		else {
			cout << "Вы победили!" << endl;
			balance += bet;
		}
	}
	else {
		cout << "Ваши карты: " << endl;
		i = 0;
		while (player[i][0] != "0") {
			char symbol = '-', space = ' ';
			cout << " " << setw(9) << setfill(symbol) << symbol << endl;
			cout << "|";
			if (player[i][0] == "10") {
				cout << setw(5) << setfill(space) << space;
			}
			else {
				cout << setw(6) << setfill(space) << space;
			}
			cout << player[i][0] << " " << player[i][1] << "|" << endl;
			for (int j = 0; j < 6; j++) {
				cout << "|";
				cout << setw(9) << setfill(space) << space << "|" << endl;
			}
			cout << setw(9) << setfill(symbol) << symbol << endl;

			i++;
		}
		cout << "Ваши очки: " << GetSum(player) << endl;
		cout << "Вы проиграли!" << endl;
		balance -= bet;
	}


	this_thread::sleep_for(std::chrono::milliseconds(10000));
}

inline void GetCard(int& hand, vector< vector<string> >& coloda, vector< vector<string> >& player, int& temp) {
	// hand -  кол-во карт в руке
	do { temp = rand() % 52; } while (coloda[temp][0] == "0"); // генерируем новую карту, пока не встретится та, что еще есть в колоде 
	player[hand][0] = coloda[temp][0];
	player[hand][1] = coloda[temp][1];
	coloda[temp][0] = "0";
	hand++;
}