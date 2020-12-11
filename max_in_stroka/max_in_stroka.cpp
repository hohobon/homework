
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int j, max, a, N, S;
	cout << "Введите кол-во элесентов и первый элемент" << endl;
	cin >> N >> max;
	j = 1;
	S = 1;
	cout << "Введите остальную последовательность" << endl;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		if (max <= a) {
			if (max == a)
			{
				S++;
			}
			else
			{
				S = 1;
			}
			max = a;
			j = i + 1;
		}
	
	}
	cout << "max элемент" << max << endl;
	cout << "номер max элемента" << j << endl;
	cout << "кол-во max элементов" << S << endl;
}

