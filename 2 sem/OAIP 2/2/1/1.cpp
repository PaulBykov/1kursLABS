#include <iostream>

using namespace std;


int main()
{

    setlocale(LC_CTYPE, "Russian");

    int lines_count = 0;
    char file_name[255];
    
    printf("Имя первого файла: ");


    fgets(file_name, 255, stdin);
    *strchr(file_name, '\n') = 0;
    file = fopen(file_name, "r");

    int n;
    fscanf(file, "%d", &n);

    while (!feof(file))
    {
        if (fgetc(file) == '\n') //считаем кол-во строк
            lines_count++;
    }
    lines_count++;

    fseek(file, 0L, SEEK_SET); // возвращаемся в начало файла
    fscanf(file, "%d", &n);
    lines_count--;

    int** A;
    A = new int* [lines_count];    //выделение динам.памяти
    for (int i = 0; i < lines_count; i++)
        A[i] = new int[n];


    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &A[i][j]);
        }
    }

    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    fclose(file);



    //второй файл (тоже самое) (через функцию лень)

    int lines_count1 = 0;
    char file_name1[255];
    FILE* file1;
    printf("Имя второго файла: ");


    fgets(file_name1, 255, stdin);
    *strchr(file_name1, '\n') = 0;
    file1 = fopen(file_name1, "r");

    int n1;
    fscanf(file1, "%d", &n1);

    while (!feof(file1))
    {
        if (fgetc(file1) == '\n')
            lines_count1++;
    }
    lines_count1++;

    fseek(file1, 0L, SEEK_SET);
    fscanf(file1, "%d", &n1);
    lines_count1--;

    int** B;
    B = new int* [lines_count1];    //выделение динам.памяти
    for (int i = 0; i < lines_count1; i++)
        B[i] = new int[n1];


    for (int i = 0; i < lines_count1; i++) {
        for (int j = 0; j < n1; j++) {
            fscanf(file1, "%d", &B[i][j]);
        }
    }

    for (int i = 0; i < lines_count1; i++) {
        for (int j = 0; j < n1; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    fclose(file1);

    //запись

    FILE* fp = fopen("fC.txt", "w");
    
    fprintf(fp, "%d", n);
    fprintf(fp, "\n");

    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < n; j++) {
            int c = A[i][j] + B[i][j];
            fprintf(fp, "%d", c);
            fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);

	return 0;
}
