
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a, b, x01, x02, e, s;
	bool zero = true;
	cout << "cin e" << endl;
	cin >> e;
	while ((e < 0) && (e > 1))
	{
		cout << "e > 0!!!" << endl;
	}
	cout << "cin A and B" << endl;
	cin >> a >> b;
	while (a > b)
	{
		cout << " a < b!!!" << endl;
		cin >> a >> b;
	}
	while ((abs(x01 - x02) > e) && (zero != false))
	{
		x01 = (b - a) / 2 + a;
		cout << "x01 =" << x01 << endl;
		float fx0 = 0.25 * pow(x01, 3) + x01 - 1.2502;
		cout << "fx0 =" << fx0 << endl;
		float fA = 0.25 * pow(a, 3) + a - 1.2502;
		cout << "fA =" << fA << endl;
		float fB = 0.25 * pow(b, 3) + b - 1.2502;
		cout << "fB =" << fB << endl;
		if ((fx0 * fA) < 0)
		{
			x02 = x01;
			b = x01;

		}
		else if ((fx0 * fB) < 0)
		{
			x02 = x01;
			a = x01;
		}
		else
		{
			zero = false;
		}

	}
	if (zero == false)
	{
		cout << "net korney" << endl;
	}
	else
	{
		cout << "koren =" << x01 << "   x01 :" << x01 << "   x02 :" << x02;
	}
	return 0;
}