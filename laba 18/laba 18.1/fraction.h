#pragma once
class fraction
{
public:
	void init(double, double);
	void Read();
	void Show();
	void Root();
	double getFirst();
	double getSecond();
private:
	double first;
	double second;
};