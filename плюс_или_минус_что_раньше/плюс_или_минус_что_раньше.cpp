#include <iostream>
using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
bool f = false;
int a, N;
cout << "Введите кол-во элементов и первый элемент" << endl;
cin >> N;
int i = 1;
while ((i <= N) && (f == false))
{
	cin >> a;
	if (a == 0)
	{
		i = i + 1;
	}
	else
	{
		f = true;
	}
}
	if (f == true)
	{
		if (a < 0)
		{
			cout << "Отрицательное " << endl;
		}
		else
		{
			cout << "Положительное" << endl;
		}
	}
	else
	{
		cout << "Все элементы нулевые" << endl;
	}

	return 0;
}


