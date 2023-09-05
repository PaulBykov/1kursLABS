#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    string str;
    fstream inp("file1.txt", ios::in);
    fstream out("file2.txt", ios::out);

    int space_count = 0;
    bool is_space = false;
    while (getline(inp, str))
    {
        
        if (str.front() == 'A') {
            is_space = false;
            out << str << "\n";
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ' ') {
                    space_count++;
                    is_space = true;
                }
            }
            if (!is_space) {
                space_count++;
            }
        }
           
    }
	space_count++;
    std::cout << "Количество слов в file2 = " << space_count << endl;
    inp.close();
    out.close();
    return 0;
}
