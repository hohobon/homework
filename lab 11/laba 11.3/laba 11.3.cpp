#include <iostream>
#include <stack>
using namespace std;

void print(stack<char> st)
{
	int p = st.size();
	for (int i = 0; i < p; i++)
	{
		cout << st.top() <<" ";
		st.pop();
	}
	cout << endl << endl;
}

int sizein()
{
	int a;
	cout << "Введите размер списка" << endl;
	cin >> a;
	while (a <= 0)
	{
		cout << "Размер не может быть отрицательным или меньше 0:" << endl;
		cin >> a;
	}
	return a;
}

stack<char> make(int a)
{
	char с;
    stack <char> st;
	for (int i = 0; i < a; i++)
	{
		cin >> с;
		st.push(с);
	}
	cout << "Ваш стек:"<< endl;
	print(st);
	return st;
}

void clearS(stack <char> &st)
{
	int p = st.size();
	for (int i = 0; i < p; i++)
	{
		st.pop();
	}
}

void change(stack<char> &st,int  k)
{
	char a;
	int p = st.size();
	cout << "Введите добавляемый элемент:" << endl;
	cin >> a;
	cout << endl;
	stack<char> alt;

		for (int i = 0; i <= p - k; i++)
		{
			alt.push(st.top());
			st.pop();
		}
		st.push(a);
		for (int i = 0; i <= p - k; i++)
		{
			st.push(alt.top());
			alt.pop();
		}
		clearS(alt);
		print(st);
		clearS(st);
}

int main()
{
	system("chcp 1251>nul");
	int size = sizein();
    stack <char> st = make(size);
	int k;
	cout << endl;
	cout << "Введите номер Элемента:" << endl;
	cin >> k;
	while (k <= 0 || k >st.size())
	{
		cout << "номер элемента должен быть от 1 до "<< st.size()+1 <<endl;
		cin >> k;
	}
	change(st,k);
    return 0;
}

