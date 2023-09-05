#include <iostream>
#include <string>
#include <vector>
#include <chrono>

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
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "\t" << table[i][j].address << " - " << table[i][j].surname << endl;
                }
            }
        }
    }

    void deleteEmail(string address) {
        for (int i = 0; i < table.size(); i++) {
            if (table[i].size() > 0) {
                for (int j = 0; j < table[i].size(); j++) {
                    if (table[i][j].address == address) {
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
    vector<vector<EmailAddress>> table;
    int hashFunction(int year) {
        return year % table.size();
    }
};


int main() {

    HashTable table(128);


    int choice = 0;
    while (choice != 6) {
        cout << "Menu:\n";
        cout << "1. Add new email address\n";
        cout << "2. Search for email addresses by year\n";
        cout << "3. Delete email address\n";
        cout << "4. Clear the table\n";
        cout << "5. Output\n";
        cout << "6. Exit\n";
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
            double startTime, endtTime;
            int year;
            cout << "Enter year: ";
            cin >> year;

            auto begin = std::chrono::steady_clock::now();


            vector<EmailAddress> emails = table.getEmails(year);

            auto end = std::chrono::steady_clock::now();


            auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            std::cout << "The time: " << elapsed_ms.count() << " nanosec\n";


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
        case 3: {
            string address;
            cout << "Enter email address to delete: ";
            cin >> address;
            table.deleteEmail(address);
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
