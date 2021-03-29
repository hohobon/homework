#include <iostream>


using namespace std;

struct LIST
{
    char data;
    LIST *next;
};

void del(LIST* First)
{
    LIST* p = First;

    while (p != NULL)
    {
        LIST* old = p;
        p = p->next;
        delete old;
    }
}

void add(LIST*& first,int k,int size)
{
    LIST* p = first;
    int num = 1;
    LIST* old = first;
    while (p != NULL)
    {
        if (num == k)
        {
            LIST* h = new LIST;
            cout << "Введите элемент" << endl;
            cin >> h->data;
            h->next = p;
            old->next = h;
        }
        old = p;
        p = p->next;
        num++;
    }
}

void print(LIST* First)
{
    if (First == NULL)
    {
        cout << "Список пустой" << endl;
    }
    else
    {
        LIST* p = First;
        while (p != NULL)
        {
            cout << p->data << "\t";
            p = p->next;
        }
        cout << endl;
    }
}

LIST* make(int size)
{
    LIST* first, * p;
    first = NULL;
    cout << "Введите первый элемент" << endl;
    p = new LIST;
    cin >> p->data;
    first = p;
    for (int i = 1; i < size; i++)
    {
        LIST* h = new LIST;
        p->next = h;
        p = p->next;
        cout << "Введите " << i << "элемент"<< endl;
        cin >> p->data;
        p->next = NULL;
        
    }
    return first;
}

int main()
{
    system("chcp 1251>nul");
    int size, k;
    cout << "Введите размер списка" << endl;
    cin >> size;

    while (size <= 0)
    {
        cout << "Размер должен быть не меньше 1" << endl;
        cin >> size;
    }

    LIST* List = make(size);
    cout << "Ваш список" << endl;
    print(List);
    cout << "Введите номер добаляемого элемента" << endl;
    cin >> k;
    while (k<0 || k >size)
    {
        cout << "Номер элмента должен быть от " << 0  <<" до "<< size << endl;
        cin >> k;
    }
    add(List,k, size);
    print(List);
    del(List);
    return 0;
}

