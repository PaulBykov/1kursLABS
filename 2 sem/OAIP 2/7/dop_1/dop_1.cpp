#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct first_half
{
	string number;
	first_half* next;
};

struct two_half
{
	string number;
	two_half* next;
};

void pop_first_half(first_half*& ptr) {
	string tmp = ptr->number;
	first_half* pp = ptr;
	ptr = ptr->next;
	cout << tmp;
}

void pop_two_half(two_half*& ptr) {
	string tmp = ptr->number;
	two_half* pp = ptr;
	ptr = ptr->next;
	cout << tmp;
}

void push_first_half(first_half*& ptr, string num) {
	first_half* pp = new first_half;
	pp->number = num;
	pp->next = ptr;
	ptr = pp;
}
void push_two_half(two_half*& ptr, string num) {
	two_half* pp = new two_half;
	pp->number = num;
	pp->next = ptr;
	ptr = pp;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	first_half* p_first_half = nullptr;
	two_half* p_two_half = nullptr;
	string str, buff_str;
	cout << "Введите строку: ";
	getline(cin, str);
	int size = str.length();
	for (int i = 0; i < size / 2; i++)
	{
		buff_str = str[i];
		push_first_half(p_first_half, buff_str);
	}

	for (int i = size / 2; i < size; i++)
	{
		buff_str = str[i];
		push_two_half(p_two_half, buff_str);
	}

	for (int i = 0; i < size / 2; i++)
	{
		buff_str = str[i];
		pop_first_half(p_first_half);
	}

	for (int i = size / 2; i < size; i++)
	{
		buff_str = str[i];
		pop_two_half(p_two_half);
	}
}