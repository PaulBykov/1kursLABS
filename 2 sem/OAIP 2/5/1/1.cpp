#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

enum SUBJECTS {
    math = 1, rus, geo, phy, his
};

char c;

struct STUDENT {

    string name;
    string lastname;
    string surname;
    string studLife;
    float avg;

    struct KLASS {
        unsigned numb : 4;
        unsigned letter : 5;
    } klass;

    void input() {
        cin.ignore();
        cout << "Фамилия ученика: ";
        getline(cin, surname);

        cout << "Имя ученика: ";
        getline(cin, name);

        cout << "Отчество ученика: ";
        getline(cin, lastname);

        for (int i = 0; i < 5; i++) {
            cout << "Выберите предмет\n(1 - Матем, 2 - Русский, 3 - География, 4 - Физика, 5 - История)\n";
            unsigned int variable;
            cin >> variable;
            int oc = 0;
            float avg = 0.0;
            switch (variable)
            {
            case SUBJECTS::math:
                cout << "Введите отметку: ";
                cin.ignore();
                cin >> oc;
                if (oc < 0 || oc > 9) {
                    cout << "Ошибка ввода!";
                }
                avg += oc;
                break;
            case SUBJECTS::rus:
                cout << "Введите отметку: ";
                cin.ignore();
                cin >> oc;
                if (oc < 0 || oc > 9) {
                    cout << "Ошибка ввода!";
                }
                avg += oc;
                break;
            case SUBJECTS::geo:
                cout << "Введите отметку: ";
                cin.ignore();
                cin >> oc;
                if (oc < 0 || oc > 9) {
                    cout << "Ошибка ввода!";
                }
                avg += oc;
                break;
            case SUBJECTS::phy:
                cout << "Введите отметку: ";
                cin.ignore();
                cin >> oc;
                if (oc < 0 || oc > 9) {
                    cout << "Ошибка ввода!";
                }
                avg += oc;
                break;
            case SUBJECTS::his:
                cout << "Введите отметку: ";
                cin.ignore();
                cin >> oc;
                if (oc < 0 || oc > 9) {
                    cout << "Ошибка ввода!";
                }
                avg += oc;
                break;
            default:
                cout << "Вы ввели неверное значение";
                break;
            }
        }
        



        cin.ignore();
        unsigned int numb, let;
        char ch;
        cout << "Введите номер класса, букву класса ";
        cin >> numb >> ch;
        klass.numb = numb;
        klass.letter = (int) ch;
        c = ch;

        cin.ignore();
    }

    
    void output() {
        if (surname != "") {
            cout << "---------------------------------\n";
            cout << "ФИО: " << surname << " " << name << " " << lastname << endl;
            cout << "Класс: " << klass.numb << c << endl;
            cout << "Средний балл " << 5.0 << endl;
            cout << "---------------------------------\n";

        }
    }

    void del() {
        name = "";
        surname = "";
        lastname = "";
        avg = 0;
        klass.numb = 0;
        klass.letter = 0;
    }

    bool searh(string studLife) {
        return this->studLife == studLife;
    }
};
 

int main() {

        setlocale(LC_ALL, "Rus");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int variable, num;
        STUDENT student[10];

        do
        {
            cout << "1 - Ввод нового ученика\n"
                << "2 - Вывод всех учеников\n"
                << "3 - Удалить ученика\n"
                << "4 - Поиск ученика\n"
                << "0 - Выход\n";
            cout << "Выберите опцию: ";
            cin >> variable;
            switch (variable)
            {
            case 1:
            {
                cout << "Введите кол-во учеников, которое хотите ввести: ";
                cin >> num;
                for (int i = 0; i < num; i++)
                {
                    student[i].input();
                }
                break;
            }
            case 2:
            {
                for (int i = 0; i < 10; i++)
                {
                    student[i].output();
                }
                break;
            }
            case 3:
            {
                cout << "Введите списочный номер, который хотите удалить: ";
                cin >> num;
                for (int i = 0; i < 10; i++)
                {
                    if (num == i)
                        student[i].del();
                }
                break;
            }
            case 4:
            {
                string studLife;
                cin.ignore();
                cout << "Введите Фамилию: ";
                getline(cin, studLife);

                for (int i = 0; i < 10; i++)
                {
                    if (student[i].searh(studLife)) {
                        student[i].output();
                    }
                }
                break;
            }
            default:
                cout << "Вы ввели не верное значение\n";
                break;
            }
        
        } while (variable != 0);
}
