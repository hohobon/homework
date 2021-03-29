#include <iostream>
#include <iterator>
#include <list>
#include <ctime>
using namespace std;

int sizein()
{
	int a;
	cout << "Введите размер списка" << endl;
	cin >> a;
	while (a <= 0)
	{
		cout << "Размер не может быть меньше или равным нулю" << endl;
		cin >> a;
	}
	return a;
}

void print(list<double>a)
{
	copy(a.begin(), a.end(),ostream_iterator<double>(cout ," "));
	cout << endl;
}

void make(list<double> &a, int size)
{
	srand(time(0));
	char c;
	int b;
	cout << "Ввести с клавиатуры Y/N" << endl;
	cin >> c;
	if (c == 'n')
	{
		for (int i = 0; i < size; i++)
		{
			a.push_back(rand() % 100);
		}
	}
	else 
	{
		for (int i = 0; i < size; i++)
		{
			cin >> b;
			a.push_back(b);
		}
	}
	print(a);
}

void remove(list<double>& a)
{
	list<double> additional;
	int counter = 1;

		for (list<double>::iterator it = a.begin(); it != a.end(); ++it)
		{
			if (counter % 2 != 0)
			{
				additional.push_back(*it);
			}
			counter++;
		}
	

	a = additional;
	additional.clear();
}

int main()
{
	system("chcp 1251>nul");
	int size = sizein();
	list<double> myList;
	make(myList, size);
	if (size == 1)
	{
		cout << "Так как в ВАШЕМ списке ОДИН эелемент, то изменять нечего ахазазазззаззахахазахзхаз" << endl;
	}
	else
	{
		cout << "Изменённый список :" << endl;
		remove(myList);
	}
	print(myList);
	myList.clear();
	return 0;
}
