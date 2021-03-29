#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::init(double F, double S)
{
	first = F;
	second = S;
}

void fraction::Read()
{
	cout << "\nfirst?"; cin >> first;
	cout << "\nsecond?"; cin >> second;
}
void fraction::Show()
{
	cout << "first :" << first << endl;
	cout << "second :" << second << endl;
}

void fraction :: Root()
{
	if (first == 0) cout << "Корней нет" << endl;
	else 
	{
		double root = (-second) / first;
		cout << "Корень уравнения y = " << first << "x + " << second << endl << "Корень :" << root;
	}
}

double fraction:: getFirst()
{
	return first;
}
double fraction:: getSecond()
{
	return second;
}

