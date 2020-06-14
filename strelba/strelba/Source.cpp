#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
void menu();
void result(int** n, int* n1, int a, int b);
void pobedit(int* n, int a);

int main()	{
	setlocale(LC_ALL, "Russian");
	int n, m, key = 1;
	menu();
	cin >> key;
	srand(time(NULL));
	do
		switch (key)	{

		case 0:
			cout << "�����\n";
			break;

		case 1:
			n = rand() % 31;
			m = rand() % 11;
			break;

		case 2:
			cout << "������� n � m\n";
			cin >> n;
			cin >> m;
			break;

		default:
			cout << "������!\n";
			break;
		}

	while (n == 0 || m == 0 || n == 1 || m == 1);
	cout << "����� ��������:" << n << "\n���������� ���������:" << m << "\n";
	int** a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % 11;

	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++)	{
			printf("%5d", a[i][j]);
		}
		cout << endl;
	}

	int* res;
	res = new int[n];
	result(a, res, n, m);
	pobedit(res, n);
	return 0;
}

void menu()	{
	cout << "�������� ��������:\n";
	cout << endl;
	cout << "0 - �����\n";
	cout << "1 - ��������� ��������\n";
	cout << "2 - ������ ����\n";
}

void result(int** n, int* n1, int a, int b)	{
	int s;

	for (int i = 0; i < a; i++)	{
		s = 0;
		for (int j = 0; j < b; j++)
			s += n[i][j];
		n1[i] = s;
	}

	cout << "\n����������: ";
	for (int i = 0; i < a; i++)
		cout << n1[i] << " ";
}

void pobedit(int* n, int a) {
	int max;
	max = n[0];
	for (int i = 0; i < a; i++) {
		if (n[i] > max)
			max = n[i];
	}

	cout << "\n" << max << "\n����������: ";

	for (int i = 0; i < a; i++) {
		if (n[i] == max) {
			cout << "������� ����� " << i + 1 << endl;
		}

	}
}