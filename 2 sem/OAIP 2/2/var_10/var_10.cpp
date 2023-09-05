#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int sfagfsags() {
	setlocale(LC_ALL, "Rus");
	float diff, min = 100, y = 0, number;
	FILE* fA;
	int num;
	printf("Введите число для сравнения: ");
	cin >> num;

	fopen_s(&fA, "fA.txt", "w");

	if (fA == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	printf("Числа записаны в файл\n");
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++)
	{
		y = 0.1 * (rand() % 1001 - 500);
		fprintf(fA, "%.1f ", y);
	}
	fclose(fA);
	fopen_s(&fA, "fA.txt", "r");
	if (fA == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	printf("Числа считаны из файла\n");
	for (int i = 0; i < 20; i++)
	{
		fscanf_s(fA, "%f", &y);
		diff = abs(y - num);
		if (min > diff) {
			min = diff;
			number = y;
		}

	}
	printf("Число ближайшее к введенному %.1f ", number);
	fclose(fA);
	return 0;
}

int main() {
	setlocale(LC_ALL, "Rus");
	FILE* file, * file1;
	char str[256];
	int N;
	printf("Введите количество строк, которое хотите ввести: ");
	cin >> N;

	fopen_s(&file, "F1.txt", "w");
	if (file == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i <= N; i++)
	{
		cin.getline(str, 256);

		fprintf(file, "%s\n", str);
	}
	printf("\nСтроки записаны\n");
	fclose(file);

	fopen_s(&file, "F1.txt", "r");
	fopen_s(&file1, "F2.txt", "w");
	if (file == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	if (file1 == NULL) {
		perror("Ошибка открытия файла\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i <= N; i++)
	{
		fgets(str, 30, file);
		if (!(i % 2)) {
			fprintf(file1, "%s", str);
			printf("%s", str);
		}
	}
	return 0;
}