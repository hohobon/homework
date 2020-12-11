#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	bool zero = true;

	double a, b, x, x01, x02, e;
	


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
	cout << "cin >> x " << endl;
	cin >> x;
	while ((x < a) && (x > b))
	{
		cout << " a < x < b !!!" << endl;
		cin >> x;
	}
	double fdx = 0.25 * pow(x, 3) + x - 1.2502;
	double fpx = 0.25 * 3 * pow(x, 2) + 1;
	x01 = x - (fdx / fpx);
	x02 = x;
	if (abs(x01 - x02) < e)
		zero = false;
	x02 = x01;
	do
	{
		double fdx = 0.25 * pow(x02, 3) + x02 - 1.2502;
		double fpx = 0.25 * 3 * pow(x02, 2) + 1;
		x01 = x02 - (fdx / fpx);
		
		if (abs(x01 - x02) <= e)
			zero = false;
		else
			x02 = x01;
	} while (zero != false); 
	if (zero == false)
		cout << "/n koren =  " << x01;
	

	return 0;
}