#include <iostream>
using namespace std;

void print(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void del(int k, int** matrix,int a, int b)
{
	int m = a - 1;
	int** buffer = new int* [m];
	for (int i = 0; i < a - 1; i++)
	{
		buffer[i] = new int[b];
	}
	for (int i = 0; i < k-1; i++) 
	{
		for (int j = 0; j < b; j++)
		{
			buffer [i][j] = matrix[i][j];
		}
	}
	for (int i = k; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			buffer[i-1][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < a; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = buffer;
	cout << endl << "Матрица , без " << k <<"-ой строки"<< endl;
	print(matrix, a-1, b);
	for (int i = 0; i < a-1; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

}

int** arraymaker(int m, int n)// функция отвечающая за создание и запонение массива(матрицы)
{
	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand()%100;
		}
	}
	return matrix;
}

int main()
{
	system("chcp 1251>nul");
	int a, b, k;
	cout << "Введите размеры матрицы" << endl << "Введите кол-во строк :";
	cin >> a;
	while ((a <= 0)||(a == 1))
	{
		cout << "Кол-во столбцов не должно быть отрицательным, равно нулю, " << endl;
		cin >> a;
	}
	cout << "Введите кол-во столбцов :";
	cin >> b;
	while (b <= 0)
	{
		cout << "Кол-во столбцов не должно быть отрицательным или равно нулю" << endl;
		cin >> b;
	}
	int** matrix = arraymaker(a, b);
	cout << endl << "Матрица: " << endl;
	print(matrix, a, b);
	cout << "Введите номер строки которую удалить " << endl;
	cin >> k;
	while ((k <= 0) || (k > a))
	{
		cout << "K должно быть от " << 0 << "до " << a+1 << endl;
		cin >> k;
	}
	del(k, matrix, a, b);

	return 0;
}

