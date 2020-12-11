#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	bool zero = true;
	 
	double a, b, x01, x02, e, i;
	i = 0;
	
	
	 cout << "cin e" << endl;
	cin >> e;
	while ((e < 0) && (e > 1))
	{
		cout << "e > 0!!!" << endl;
		cin >> e;
	}
	cout << "cin A and B" << endl;
	cin >> a >> b;
	while (a > b)
	{
		cout << " a < b!!!" << endl;
		cin >> a >> b;
	}
	x01 = (b - a) / 2 + a;
	cout << "x01 =" << x01 << endl;
	double fx0 = 0.25 * pow(x01, 3) + x01 - 1.2502;                        cout << "fx0 =" << fx0 << endl;
	double fA = 0.25 * pow(a, 3) + a - 1.2502;                             cout << "fA =" << fA << endl;
	double fB = 0.25 * pow(b, 3) + b - 1.2502;                             cout << "fB =" << fB << endl;
	if ((fx0 * fA) < 0)
	{
		b = x01;   
		cout << "new B =  " << b << endl;
	}
	else if ((fx0 * fB) < 0)
	{

		a = x01; 
		cout << "new A =  " << a << endl;
	}
	

	do
	{
		i++;
		x02 = x01;
		cout << "new x02 =  " << x02 << endl;
		x01 = (b - a) / 2 + a;
		cout << "x01 =" << x01 << endl;
		double fx0 = 0.25 * pow(x01, 3) + x01 - 1.2502;                        cout << "fx0 =" << fx0 << endl;
		double fA = 0.25 * pow(a, 3) + a - 1.2502;                             cout << "fA =" << fA << endl;
		double fB = 0.25 * pow(b, 3) + b - 1.2502;                             cout << "fB =" << fB << endl;
		if ((fx0 * fA) < 0)
		{

			b = x01;
			cout << "new B =  " << b << endl;

		}
		else if ((fx0 * fA) == 0)
			zero = false;
		else if ((fx0 * fB) < 0)
		{

			a = x01;
			cout << "new A =  " << a << endl;
		}
		else if ((fx0 * fB) == 0)
		{
			zero = false;
		}
		if ((abs(x02 - x01) <= e) || (x02 - x01) == 0)
			zero = false;
	} while (zero != false); 
		
	cout << "x01  = " << x01 << "   x02 =  " << x02;

	return 0;
}