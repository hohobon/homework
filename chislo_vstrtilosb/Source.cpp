#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	bool f = true; 
	cout << "������� ������ 2 ����� ������������������" << endl;
	cin >> a >> b;
	if ((a != 0) && (b != 0))
	{
		cout << "����� ��������� ������������������ ������� 0" << endl;
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
			cout << "������������������ ������������" << endl;
		}
		else
		{
			cout << "������������������ �� �����������" << endl;
		}
	}
	else
	{
		cout << " 0 " << endl;
	}
	
	return 0;
}