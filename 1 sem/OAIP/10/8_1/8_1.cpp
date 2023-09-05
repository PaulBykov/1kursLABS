#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	char tmp[33];
	int A, maskA;
	cout << "A=";
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << tmp << endl;
	int i = 0, k = 0;
	while (isdigit(tmp[i])) {
		i++;
	}
	i--;

	while (i >= 0) {
		if (tmp[i] == '1') {
			k++;
			if (k == 3) {	
				tmp[i] = '0';
				k = 0;
			}
		}
		i--;
	}

	cout << tmp << endl;

	return 0;
}
