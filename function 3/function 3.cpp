#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	bool zero = true;

	double a;
	double b;
	double x;
	double x01;
	double e;

	cout << "cin e" << endl;
	cin >> e;
	while ((e < 0) && (e > 1))
	{
		cout << "e > 0!!!" << endl;
		cin >> e;
	}
	cout << "cin >> x " << endl;
	cin >> x01;
	double x02 = -1 * (0.25 * pow(x01, 3) - 1.2502);
	if (abs(x01 - x02) < e)
		zero = false;
	x01 = x02;
	do
	{
		double x02 = -1 * (0.25 * pow(x01, 3) - 1.2502);
		
		if (abs(x01 - x02) <= e)
			zero = false;
		else
			x01 = x02;
	} while (zero != false);
	if (zero == false)
		cout << "/n koren =  " << x01;


	return 0;
}