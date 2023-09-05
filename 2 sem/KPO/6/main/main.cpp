#include <iostream>
#include "..\StaticLib\StaticLib.cpp"




using namespace std;
using namespace Dictionary;

int main() {
	setlocale(LC_ALL, "Rus");

	try {
#if (defined(TEST_CREATE_01)+ defined(TEST_CREATE_02)+ defined(TEST_ADDENTRY_03)+ defined(TEST_ADDENTRY_04)+ defined(TEST_GETENTRY_05)+ defined(TEST_DELENTRY_06)+ defined(TEST_UPDENTRY_07)+ defined(TEST_UPDENTRY_08)+ defined(TEST_DICTIONARY) > 1)
#error Only one test allowed!
#endif


#ifdef TEST_CREATE_01
		Instance test = Create("Максимальная длиннаааааа", 5);

#elif defined TEST_CREATE_02
		Instance test = Create("Преподаватели", 50000);

#elif defined TEST_ADDENTRY_03
		Instance test = Create("Тест", 1);
		Entry test_entry1 = { 1,"Быков" }, test_e2 = { 2,"Розель" };
		AddEntry(test, test_entry1);
		AddEntry(test, test_e2);

#elif defined TEST_ADDENTRY_04
		Instance test = Create("Тест", 5);
		Entry test_entry = { 1,"Быков" };
		AddEntry(test, test_entry);
		AddEntry(test, test_entry);

#elif defined TEST_GETENTRY_05
		Instance test = Create("Тест", 5);
		Entry test_entry = { 1,"Быков" };
		AddEntry(test, test_entry);
		GetEntry(test, 2);

#elif defined TEST_DELENTRY_06
		Instance test = Create("Тест", 5);
		Entry test_entry = { 1,"Быков" };
		AddEntry(test, test_entry);
		DelEntry(test, 2);

#elif defined TEST_UPDENTRY_07
		Instance test7 = Create("Тест", 5);
		Entry test_e7 = { 1,"Быков" }, test_upd_e7 = { 2,"Розель" };
		AddEntry(test7, test_e7);
		UpdEntry(test7, 3, test_upd_e7);

#elif defined TEST_UPDENTRY_08
		Instance test = Create("Тест", 5);
		Entry test_entry = { 1,"Быков" }, test_upd_e = { 1,"Розель" };
		AddEntry(test, test_entry);
		UpdEntry(test, 1, test_upd_e);
#else
		Instance d1 = Create("Преподаватели", 7);
		Entry e1 = { 1, "Мущук" }, e2 = { 2, "Мисевич" }, e3 = { 3, "Смелов" }, e4 = { 4, "Комарова" }, e5 = { 5, "Пацей" }, e6 = { 6, "Жук" }, e7 = { 7, "Белодед" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		AddEntry(d1, e5);
		AddEntry(d1, e6);
		AddEntry(d1, e7);
		Entry ex2 = GetEntry(d1, 4);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Наркевич" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);

		Instance d2 = Create("Студенты", 7);
		Entry s1 = { 1, "Быков" }, s2 = { 2, "Могилев" }, s3 = { 4, "Лахвич" }, s4 = { 5, "Попович" }, s5 = { 6, "Русецкий" }, s6 = { 7, "Касперович" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		AddEntry(d2, s4);
		AddEntry(d2, s5);
		AddEntry(d2, s6);
		Entry newentry3 = { 3, "Розель" };
		UpdEntry(d2, 4, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
#endif;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}