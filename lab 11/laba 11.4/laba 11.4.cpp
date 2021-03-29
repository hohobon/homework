#include <iostream>
#include<queue>
using namespace std;
double* arr;

void print(queue<double> qu)
{
	int p = qu.size();
	for (int i = 0; i < p; i++)
	{
		arr[i] = qu.front();
		cout << qu.front() << " ";
		qu.pop();
	}
	for (int i = 0; i < p; i++)
	{
		qu.push(arr[i]);
	}
	cout << endl;
}

void remove(queue<double>& qu)
{
	int p = qu.size();
	int counter = 1;
	int meme = 0;
	for (int i = 0; i < p; i++)
	{
		if (counter % 2 != 0)
		{
			arr[meme] = qu.front();
			qu.pop();
			
		}
		else
		{
			qu.pop();
			meme++;
		}
		counter++;
	}
	for (int i = 0; i <p - meme; i++)
	{
		qu.push(arr[i]);
	}
	cout <<"Очередь после изменения"<< endl;
	print(qu);
	for (int i = 0; i < qu.size(); i++)
	{
		qu.pop();
	}
}


	

int main()
{
	system("chcp 1251>nul");
	int n;
	cout<<"Введите размер очереди"<<endl;
	cin >> n;
	while (n <= 0)
	{
		cout << "Размер очереди не долен быть меньше ил иравен нулю" << endl;
		cin >> n;
	}
	arr = new double[n];
	queue<double> qu;
	for (int i = 0; i < n; i++)
	{
		double a;
		cin >> a;
		qu.push(a);
	}
	print(qu);
	remove(qu);
	return 0;
}
