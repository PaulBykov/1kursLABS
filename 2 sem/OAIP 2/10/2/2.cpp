#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll max(ll m, ll n) {
    return n > m ? n : m;
}

ll F(ll m, ll n) {
    if ((n + m) % 2 == 0) {
        return max(n, m);
    }
    ll half = (n + m + 1) / 2;
    return ( F(half, n + 1) + F(m, half) );
}


int main()
{
    ll n, m;
    cout << "Enter any valid number's n, m: ";
    cin >> n >> m;
    cout << "F(m, n) = " << F(m, n);

}
