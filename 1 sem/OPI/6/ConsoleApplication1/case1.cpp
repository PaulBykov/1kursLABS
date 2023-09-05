#include <iostream>

using namespace std;

inline void case1() {

    char symbol;

    while (true) {  
        cin >> symbol;
        if (symbol == '4') {
            break;
        }
        if ( isalpha(symbol) ) {
            cout << (int)symbol - (int)toupper(symbol);
        }
        else {
            cout << "Îøèáêà!";
        }
    }
}