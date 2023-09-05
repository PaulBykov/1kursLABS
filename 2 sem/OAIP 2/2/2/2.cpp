#include <iostream>

using namespace std;


int main()
{

    FILE* file = fopen("f.txt", "r");
    int numbers[255];

    for (int i = 0; !feof(file); i+=20) {
        for (int j = 0; j < 11; j++) {
            fscanf(file, "%d", &numbers[j]);
        }
        for (int j = 11; j < 21; j++) {
            fscanf(file, "%d", &numbers[j]);
        }

        FILE* file1 = fopen("g.txt", "w");

        for (int k = 0; k < 5; k++) {

            fprintf(file1, "%d", (numbers[k]));
            fprintf(file1, " ");

        }
        for (int k = 0; k < 5; k++) {


            fprintf(file1, "%d", (numbers[k + 10]));
            fprintf(file1, " ");

        }
            for (int k = 0; k < 5; k++) {


                fprintf(file1, "%d", (numbers[k + 5]));
                fprintf(file1, " ");

            }
            for (int k = 0; k < 5; k++) {


                fprintf(file1, "%d", (numbers[k + 15]));
                fprintf(file1, " ");

            }
            fclose(file1);
    }
    
    fclose(file);

    

    return 0;
}
