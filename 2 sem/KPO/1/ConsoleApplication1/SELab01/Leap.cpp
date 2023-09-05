#include <iostream>


using namespace std;


inline bool isLeap(int year) {
    bool vis = false;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                vis = true;
            }
        }
        else {
            vis = true;
        }
    }
    return vis;
}