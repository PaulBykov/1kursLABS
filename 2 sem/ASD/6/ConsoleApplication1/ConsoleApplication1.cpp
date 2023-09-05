#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct EmailAddress {
    string address;
    string surname;
    int year;
};

class HashTable {
public:
    HashTable(int size) {
        table.resize(size);
    }

    void addEmail(EmailAddress email) {
        int index = hashFunction(email.year);
        table[index].push_back(email);
    }

    vector<EmailAddress> getEmails(int year) {
        int index = hashFunction(year);
        return table[index];
    }

    void printTable() {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                cout << "Year " << i << ":\n";
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "\t" << table[i][j].address << " - " << table[i][j].surname << endl;
                }
            }
        }
    }

private:
    vector<vector<EmailAddress>> table;
    const int hash = 5120;
    int hashFunction(int year) {
        return hash % table.size();
    }

    /* static unsigned int hash(const std::string& key, unsigned int p = 1000000007, unsigned int a = 31, unsigned int b = 17, unsigned int m = 1000) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = ((hash * a + c) % p + b) % m;
        }
        return hash;
    }*/
};

int main() {


    HashTable table(10);

    int choice = 0;
    while (choice != 3) {
        cout << "Menu:\n";
        cout << "1. Add new email address\n";
        cout << "2. Search for email addresses by year\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string address, surname;
            int year;
            cout << "Enter email address: ";
            cin >> address;
            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter year: ";
            cin >> year;
            table.addEmail({ address, surname, year });
            break;
        }
        case 2: {
            int year;
            cout << "Enter year: ";
            cin >> year;
            vector<EmailAddress> emails = table.getEmails(year);
            if (emails.size() == 0) {
                cout << "No email addresses found for year " << year << endl;
            }
            else {
                cout << "Email addresses for year " << year << ":\n";
                for (int i = 0; i < emails.size(); i++) {
                    cout << "\t" << emails[i].address << " - " << emails[i].surname << endl;
                }
            }
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

        cout << endl;
    }

    return 0;
}
