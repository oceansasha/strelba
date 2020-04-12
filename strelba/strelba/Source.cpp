#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void pobeditel(int** a, int n, int m);
void input(int** a, int n, int m, int z);
void output(int** a, int n, int m);


int main() {

	setlocale(LC_ALL, "RUS");
	int n, m;

	cout << "Введите количество стрелков: "; cin >> n;
	cout << "\nВведите количество выстрелов: "; cin >> m;
	cout << endl;

	int z = 10;
	int** a = new int* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	input(a, n, m, z);
	output(a, n, m);
	pobeditel(a, n, m);
	cout << "\n";
}

void pobeditel(int** a, int n, int m) {
	int max = 0, max_i = 0, count = 0, max_sum = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
				max_i = i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == max) {
				count += 1;
			}
		}
	}

	if (count > 1)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum = sum + a[i][j];
			}
			if (sum > max_sum) {
				max_sum = sum;
			}

			sum = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum = sum + a[i][j];
			}

			if (sum == max_sum) {
				cout << "\nПобедитель - стрелок под номером " << i + 1 << endl;
			}

			sum = 0;
		}
	}
	else cout << "\nПобедитель - стрелок под номером " << max_i + 1 << endl;
}

	void input(int** a, int n, int m, int z) {
		int RandomD;
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = rand() % z;
			}
		}
	}

	void output(int** a, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}
	}

