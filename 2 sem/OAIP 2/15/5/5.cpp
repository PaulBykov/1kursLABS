#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
    string name;
    int price;
};

class HashTable {
public:
    HashTable(int size) {
        table.resize(size);
    }

    void addEmail(Item email) {
        int index = hashFunction(email.price);
        table[index].push_back(email);
    }

    vector<Item> getEmails(int price) {
        int index = hashFunction(price);
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
    vector<vector<Item>> table;
    int hashFunction(int price) {
        return price % table.size();
    }
};


int main() {

    HashTable table(10);

    int choice = 0;
    while (choice != 6) {
        cout << "Menu:\n";
        cout << "1. Add new item\n";
        cout << "2. Search for name by price\n";
        cout << "3. Delete name\n";
        cout << "4. Clear the table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int price;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;
            table.addEmail({ name, price });
            break;
        }
        case 2: {
            int price;
            cout << "Enter price: ";
            cin >> price;
            vector<Item> emails = table.getEmails(price);
            if (emails.size() == 0) {
                cout << "No shools addresses found for price " << price << endl;
            }
            else {
                cout << "Shools addresses for price " << price << ":\n";
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
