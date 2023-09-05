#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

// вар 8
int task1()
{

	setlocale(LC_ALL, "Rus");

	const char* letters = "eyuioa";
	char str[100];
	int valueOfLetters = 0, maxValueOfLetters = 0, numberStr, lettersNumber = 0;
	cout << "Введите кол-во строк: ";
	cin >> numberStr;
	ofstream ofile_1("FILE_1.txt");
	for (int i = 0; i < numberStr + 1; i++)
	{
		valueOfLetters = 0;
		cin.getline(str, 100);
		for (int l = 0; letters[l] != 0; l++)
		{
			for (int j = 0; str[j] != 0; j++)
			{
				if (letters[l] == str[j])
					valueOfLetters++;
			}
		}

		if (valueOfLetters) {
			cout << "Кол-во гласных в строке " << valueOfLetters << endl;
		}
		else {
			cout << "В строке нет гласных\n";
		}
		if (maxValueOfLetters < valueOfLetters) {
			maxValueOfLetters = valueOfLetters;
			lettersNumber = i;
		}

		ofile_1 << str << endl;
	}
	cout << "Максимальное кол-во гласных в строке " << maxValueOfLetters << endl;
	cout << "Номер строки " << lettersNumber << endl;

	ofstream ofile_2("FILE_2.txt");
	ifstream ifile_1("FILE_1.txt");

	for (int i = 0; i < numberStr + 1; i++)
	{
		ifile_1.getline(str, 100);
		if (i != lettersNumber)
			ofile_2 << str << endl;
	}

	ofile_1.close();
	ofile_2.close();
	return 0;
}

void task2() {
	string str;
	int beginNum = 0, endNum = 0, counter = 0;
	getline(cin, str);
	ofstream ofile_1("FILEA.txt");
	ofile_1 << str;
	ifstream ifile_1("FILEA.txt");
	ifile_1 >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
			if (!(counter)) beginNum = i;
			counter++;
		}
	}

	cout << str.substr(beginNum, counter);
}

//3 Вариант

int task3() {

	string str, letters = "eyuioa";
	int numberStr, k, count = 0;
	ofstream ofile_1("FILE_1dop2.txt");

	cout << "Введите количество строк: ";
	cin >> numberStr;

	for (int i = 0; i < numberStr + 1; i++)
	{
		getline(cin, str);
		ofile_1 << str << endl;
	}

	ofile_1.close();

	ifstream ifile_1("FILE_1dop2.txt");
	ofstream ofile_2("FILE_2dop2.txt");

	cout << "С какой строки копировать?\n";
	cin >> k;

	int i = 0;

	while (i < k) {
		getline(ifile_1, str);
		i++;
	}

	for (int i = k; i < k + 4; i++)
	{
		getline(ifile_1, str);
		ofile_2 << str << endl;
	}

	ifile_1.close();
	ofile_2.close();

	ifstream ifile_2("FILE_2dop2.txt");

	for (int i = 0; i < k + 4; i++)
	{
		getline(ifile_2, str);

		for (int j = 0; letters[j] != '\0'; j++)
		{
			for (int k = 0; str[k] != '\0'; k++)
			{
				if (str[k] == letters[j]) {
					count++;
				}
			}
		}
	}

	cout << "Кол-во гласных" << count << endl;
	return 0;
}

int task4() {

	string str;
	int numberStr, num;
	ofstream ofile_1("fileDop2.txt");
	cout << "Введите количество строк: ";
	cin >> numberStr;
	for (int i = 0; i <= numberStr; i++)
	{
		getline(cin, str);
		ofile_1 << str << endl;
	}
	ofile_1.close();
	ifstream ifile_1("fileDop2.txt");
	ofstream ofile_2("task2dop2.txt");
	while (getline(ifile_1, str))
	{
		int i = 0;
		while (str[i] != ' ' && i < str.size()) {
			i++;
		}

		if (str[i] != ' ') {
			ofile_2 << str;
		}
	}



	return 0;
}

// вар 11

int task5() {
	string str;
	int numberStr, count = 0, min = 100;
	ofstream ofile_1("FILE_1dop1.txt");
	cout << "Введите кол-во строк: ";
	cin >> numberStr;
	for (int i = 0; i < numberStr + 1; i++)
	{
		getline(cin, str);
		ofile_1 << str << endl;
	}
	ofile_1.close();
	ifstream ifile_1("FILE_1dop1.txt");
	ofstream ofile_2("FILE_2dop1.txt");
	cout << "Сторки, которые содержат только одно слово: ";
	for (int i = 0; i < numberStr + 1; i++)
	{
		count = 0;
		getline(ifile_1, str);
		for (int j = 0; str[j] != '\0'; j++)
			if (str[j] == ' ') count++;

		if (!(count)) {
			ofile_2 << str << endl;
			cout << str << endl;
		}
	}
	ifile_1.close();
	ofile_2.close();
	string buffStr;
	ifstream ifile_2("FILE_2dop1.txt");

	for (int i = 0; i < numberStr + 1; i++)
	{
		count = 0;
		getline(ifile_2, str);
		count = str.size();
		if (min > count && count != 0) {
			min = count;
			buffStr = str;
		}
	}
	cout << "Самое котороткое слово: \n";
	cout << buffStr << endl;
	return 0;
}


int task6() {

	string str, buffStrMin, buffStrMax, buff;
	string letters = "eyuioa";
	int numberStr = 2, count = 0, min = 100, max = 0, j = 0;

	ofstream ofile_1("fileDop1.txt");
	cout << "Введите две строки строки: ";
	for (int i = 0; i < numberStr; i++)
	{
		getline(cin, str);
		ofile_1 << str << endl;
	}

	ofile_1.close();

	ifstream ifile_1("fileDop1.txt");

	for (int i = 0; i < numberStr; i++) {

		getline(ifile_1, str);

		string word;          //Буфер для считывания строки
		stringstream stream;        //Создание потоковой переменной
		stream << str;                 //Перенос строки в поток
		while (stream >> word) {
			count = word.size();
			if (!i && min > count) {
				min = count;
				buffStrMin = word;
			}
			if (i && max < count) {
				max = count;
				buffStrMax = word;
			}
		}

	}
	cout << "Самое короткое слово: " << buffStrMin << endl;
	cout << "Самое длинное слово: " << buffStrMax << endl;
	int countMin = 0, countMax = 0;
	for (int i = 0; letters[i] != '\0'; i++)
	{
		for (int j = 0; buffStrMin[j] != '\0'; j++) {
			if (buffStrMin[j] == letters[i]) {
				countMin++;
			}
		}
		for (int j = 0; buffStrMax[j] != '\0'; j++) {
			if (buffStrMax[j] == letters[i]) {
				countMax++;
			}
		}
	}

	cout << "Количество гласных в коротком слове: " << countMin << endl;
	cout << "Количество гласных в длинном слове: " << countMax << endl;
	return 0;
}



int main() {
	setlocale(LC_ALL, "Rus");
	
	task1();


	return 0;
}