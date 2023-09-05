#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string name;
    int num;
};

class HashTable {
public:
    HashTable(int size) {
        table.resize(size);
    }

    void addEmail(Book email) {
        int index = hashFunction(email.num);
        table[index].push_back(email);
    }

    vector<Book> getEmails(int num) {
        int index = hashFunction(num);
        return table[index];
    }

    void printTable() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                cout << "Year " << i << ":\n";
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "\t" << table[i][j].name << " - " << table[i][j].name << endl;
                }
            }
        }
    }

    void deleteEmail(string name) {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                for (int j = 0; j < table[i].size(); j++) {
                    if (table[i][j].name == name) {
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
    vector<vector<Book>> table;
    int hashFunction(int num) {
        return num % table.size();
    }
};


int main() {

    HashTable table(10);

    int choice = 0;
    while (choice != 6) {
        cout << "Menu:\n";
        cout << "1. Add new book\n";
        cout << "2. Search for name by num\n";
        cout << "3. Delete name\n";
        cout << "4. Clear the table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int num;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter num: ";
            cin >> num;
            table.addEmail({ name, num });
            break;
        }
        case 2: {
            int num;
            cout << "Enter num: ";
            cin >> num;
            vector<Book> emails = table.getEmails(num);
            if (emails.size() == 0) {
                cout << "No shools addresses found for num " << num << endl;
            }
            else {
                cout << "Shools addresses for num " << num << ":\n";
                for (int i = 0; i < emails.size(); i++) {
                    cout << "\t" << emails[i].name << endl;
                }
            }
            break;
        }
        case 3: {
            string name;
            cout << "Enter name to delete: ";
            cin >> name;
            table.deleteEmail(name);
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
