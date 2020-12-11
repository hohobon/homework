#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	bool f = true; 
	cout << "Введите первые 2 члена последовательности" << endl;
	cin >> a >> b;
	if ((a != 0) && (b != 0))
	{
		cout << "чтобы закончить последовательность введите 0" << endl;
		while ((f == true) && (a != b) && (b!= 0))
		{
			f = f && (a < b);
				if (f == true)
				{
					a = b;
					cin >> b;
				}
		}
		if (f == true)
		{
			cout << "Последовательность упорядоченна" << endl;
		}
		else
		{
			cout << "Последовательнотсь не упорядочена" << endl;
		}
	}
	else
	{
		cout << " 0 " << endl;
	}
	
	return 0;
}