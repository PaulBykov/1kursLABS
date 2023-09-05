#include <iostream>
#include <iomanip>

using namespace std;

bool poiskNull(bool*, int **, int **, int *, int *);
int proAB(int**, int**, int, int, int);

int main()
{
	int** A, ** B, n, m;
	bool null = false;
	setlocale(0, "ru");
	cout << "������� ������� ������� A(n*m) � B(m*n)\nn= ";
	cin >> n; cout << "m= "; cin >> m;
	A = new int* [n];
	B = new int* [m];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];
	for (int i = 0; i < m; i++)
		B[i] = new int[n];
	cout << "\n������� �������� ��������� �\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	cout << "\n������� �������� ��������� B\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> B[i][j];
		}
	cout << "\n������ A\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << A[i][j];
		cout << endl;
	}
	cout << "\n������ B\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << B[i][j];
		cout << endl;
	}
		
	null = poiskNull(&null, A, B, &n, &m);
	if (!null)
	{
		cout << "\n��������� ���������� �*�\n";
		int** C = new int* [n];
		for (int p = 0; p < n; p++)
			C[p] = new int[n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				C[i][j] = proAB(A, B, i, j, m);
				cout << setw(3) << C[i][j];
			}
			cout << endl;
		}
	}

	else
		cout << "�������� ������� � � � �� ������ �������� 0!!!";
}


bool poiskNull(bool *pnull, int**pA, int**pB, int*pn, int*pm)
{
	for (int i = 0; i < *pn; i++)
		for (int j = 0; j < *pm; j++)
			if (pA[i][j] == 0)
			{
				*pnull = true;
				break;
			}
	if(!*pnull)
		for (int i = 0; i < *pm; i++)
			for (int j = 0; j < *pn; j++)
				if (pB[i][j] == 0)
				{
					*pnull = false;
					break;
				}
	return *pnull;
}

int proAB(int **pA, int **pB, int i, int j, int m)
{
	int sum = 0;
	for (int g = 0; g < m; g++)
		sum += pA[i][g] * pB[g][j];
	return sum;
}