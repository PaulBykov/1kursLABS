#include <iostream>

using namespace std;

inline void case2() {

    char symbol;

    while (true) {
        cin >> symbol;
        if (symbol == '4') {
            break;
        }
        if ( (int)symbol >= -96 ) {
            cout << (int)symbol - (int)toupper(symbol);
        }
        else {
            cout << "Îøèáêà!";
        }
    }
}