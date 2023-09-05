#include "Call.h"

using namespace Call;

namespace Call {
    int _cdecl cdelc(int a, int b, int c) {
        return a + b + c;
    }

    int _stdcall cstd(int& a, int b, int c) {
        return a * b * c;
    }

    int _fastcall cfst(int a, int b, int c, int d) {
        return a + b + c + d;
    }
}

int main()
{
    int a = 1;

    std::cout << "cdelc: " << cdelc(1, 2, 3) << std::endl;

    std::cout << "cstd: " << cstd(a, 2, 3) << std::endl;

    std::cout << "cfst: " << cfst(1, 2, 3, 4) << std::endl;


    return 0;
}

