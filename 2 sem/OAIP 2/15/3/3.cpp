#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Shool {
    string surname;
    int num;
};

class HashTable {
public:
    HashTable(int size) {
        table.resize(size);
    }

    void addEmail(Shool email) {
        int index = hashFunction(email.num);
        table[index].push_back(email);
    }

    vector<Shool> getEmails(int num) {
        int index = hashFunction(num);
        return table[index];
    }

    void printTable() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                cout << "Year " << i << ":\n";
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "\t" << table[i][j].surname << " - " << table[i][j].surname << endl;
                }
            }
        }
    }

    void deleteEmail(string surname) {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                for (int j = 0; j < table[i].size(); j++) {
                    if (table[i][j].surname == surname) {
                        table[i].erase(table[i].begin() + j);
                        break;
                    }
                }
            }
        }
    }

    void clearTable() {
        for (int i = 0; i < table.size(); i++) {
            table[i].clear();
        }
    }

private:
    vector<vector<Shool>> table;
    int hashFunction(int num) {
        return num % table.size();
    }
};


int main() {

    HashTable table(10);

    int choice = 0;
    while (choice != 6) {
        cout << "Menu:\n";
        cout << "1. Add new shool\n";
        cout << "2. Search for surname by num\n";
        cout << "3. Delete surname\n";
        cout << "4. Clear the table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string surname;
            int num;
            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter num: ";
            cin >> num;
            table.addEmail({ surname, num });
            break;
        }
        case 2: {
            int num;
            cout << "Enter num: ";
            cin >> num;
            vector<Shool> emails = table.getEmails(num);
            if (emails.size() == 0) {
                cout << "No shools addresses found for num " << num << endl;
            }
            else {
                cout << "Shools addresses for num " << num << ":\n";
                for (int i = 0; i < emails.size(); i++) {
                    cout << "\t" << emails[i].surname << endl;
                }
            }
            break;
        }
        case 3: {
            string surname;
            cout << "Enter surname to delete: ";
            cin >> surname;
            table.deleteEmail(surname);
            break;
        }
        case 4: {
            table.clearTable();
            cout << "Table has been cleared" << endl;
            break;
        }
        case 5: {
            table.printTable();
            break;
        }
        default: {
            exit(1);
        }
        }
    }
    return 0;
}
