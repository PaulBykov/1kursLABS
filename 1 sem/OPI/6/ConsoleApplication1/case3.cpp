#include <iostream>

using namespace std;

inline void case3() {

    char symbol;

    while (true) {
        cin >> symbol;
        if (symbol == '4') {
            break;
        }
        if ( isdigit(symbol) ) {
            cout << (int)symbol;
        }
        else {
            cout << "Îøèáêà!";
        }
    }
}
