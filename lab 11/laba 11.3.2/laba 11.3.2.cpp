#include <iostream>
using namespace std;
struct STACK
{
	char data;
	STACK* prev;
};

void print(STACK * top)
{
	if (top == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{
		STACK* ptr = top;
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->prev;
		}
		cout << endl;
	}
}

STACK* make(int size)
{
	STACK* top;
	top = new STACK;
	cout << "Введите стек"<<endl;
	cin >> top->data;
	top->prev = NULL;
	for (int i = 2; i <= size; i++)
	{
		STACK* h = new STACK;
		cin >> h->data;
		h->prev = top;
		top = h;
	}
	return top;
}

void ADD(STACK*& top,int k)
{
	STACK* ptr = top;
	STACK* old = nullptr;
	int counter = 1;
	while (ptr != NULL)
	{
		if (counter == k)
		{
			STACK* h = new STACK;
			char c;
			cout <<"Введите вставляемый элемент"<<endl;
			cin >> c;
			h->data = c;
			if (old != nullptr) {
				old->prev = h;
			}
			else {
				top = h;
			}
			h->prev = ptr;
		}
		counter++;
		old = ptr;
		ptr = ptr->prev;
	}
}

void del(STACK* top) {
	STACK* el;
	el = top;
	top = top->prev;
	delete el;
}

int main()
{
	system("chcp 1251>nul");
	cout << "Введите ращмер стека" << endl;
		int size;
		cin >> size;
		while (size <= 0)
		{
			cout <<"Размер стека должен быть болше нуля" <<endl;
			cin >> size;
		}
		STACK* st = make(size);
		print(st);
		int k;
	cout << endl;
	cout << "Введите номер Элемента:" << endl;
	cin >> k;
	while (k <= 0 || k > size)
	{
		cout << "номер элемента должен быть от 1 до " << size + 1 << endl;
		cin >> k;
	}
	ADD(st, k);
	cout << "Стек полсе втавки элемента" << endl;
	print(st);
	del(st);
	return 0;
}

