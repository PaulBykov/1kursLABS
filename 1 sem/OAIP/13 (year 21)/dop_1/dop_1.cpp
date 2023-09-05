#include <iostream>
#include <sstream>
//1 вар 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char string[256], ending[32], words1[256] = {};
	puts("Введите предложение: ");
	gets_s(string);
	puts("Введите окончание: ");
	gets_s(ending);
	int endingLen = strlen(ending);
	char word[256] = {};          //Буфер для считывания строки
	stringstream x;        //Создание потоковой переменной
	x << string;                //Перенос строки в поток
	cout << "Слова с таким окончанием в предложении: ";
	while (x >> word) {
		//cout << word << " ";
		 //у каждого отдельного слова нужно проверить окончание //выборка слов
		int j = strlen(word) - endingLen;
		int spore = 0;
		for (int i = j, k = 0; word[i] != 0; i++, k++)
		{
			if (ending[k] == word[i]) {
				spore++;
				if (spore == endingLen) {
					cout << word << ' ';
				}
			}
		}
	}
}







