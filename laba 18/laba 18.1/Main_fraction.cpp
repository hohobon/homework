#include <iostream>
#include "fraction.h"
#include <math.h>
using namespace std;

fraction Make_struction(double a, double b)
{
	fraction t;
	t.init(a,b);
	return t;
}

int main()
{
	system("chcp 1251>nul");
	double a = 1, b = 2;
	fraction equal = Make_struction(a,b);
	equal.Show();
	equal.Root();
	fraction* X = new fraction;
	X->init(2, 6);
	X->Show();
	X->Root();
	fraction mas[3];
	for (int i = 0; i < 3; i++)
	{
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Root();
	}
	fraction* p_mas =new fraction[3];
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Root();
	}
	return 0;

}