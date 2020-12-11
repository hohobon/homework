#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N, z, a, i;
	cout << "Введите кол-во элеменнтов в последовательности:  ";
	cin >> N;
	cout << "Введите искомое число в последовательности:   ";
	cin >> z;
	bool f = false;
	i = 1;
	cout << "Вводите последовательность" << endl;
	while ((i <= N) && (f == false))
	{
		cin >> a;
		if (a == z)
		{
			f = true;
		}
		else
		{
			i++;
		}
	}
	if (f == true)
	{
		cout << "Число встретилось" << endl;
	}
	else
	{
		cout << "Число невстетилось" << endl;
	}

	return 0;
}

