#include <iostream>


using namespace std;

struct LIST
{
    double data;
    LIST* next;
    LIST* prev;
};

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

void Remove(LIST*& first)
{
    
    LIST* p = first;
    int count = 1;
    while (p != NULL)
    {
        if (count % 2 == 0)
        {
            
            LIST* current = p;     
            LIST* last = p->prev;
            LIST* Forv;
            if (p->next == NULL)
            {
                last->next = NULL;
            }
            else
            {
                Forv = p->next;
                last->next = Forv;
                Forv->prev = last;
            }
            p = p->next;
            delete current;
        }
        else 
        p = p->next;

        count++;
    }
    print(first);
}


LIST* make(int size)
{
    LIST* first, * p;
    first = NULL;
    cout << "Введите первый элемент" << endl;
    p = new LIST;
    cin >> p->data;
    first = p;
    if (size == 1)
    {
        p->next = NULL;
        cout << "Ваш список состоит из 1 элемента так что полюбуйтесь на него :" << endl;
    }
    else
    {
        for (int i = 2; i <= size; i++)
        {
            LIST* h = new LIST;
            LIST* p2 = p;
            p->next = h;
            p = p->next;
            cout << "Введите " << i << " элемент списка: \t";
            cin >> p->data;
            p->prev = p2;
            p->next = NULL;
        }
    }
    return first;
}

int enter()
{
    int a;
    cout << "Введите размер списка" << endl;
    cin >> a;

    while (a <= 0)
    {
        cout << "Размер должен быть не меньше 1" << endl;
        cin >> a;
    }
    return a;
}

int main()
{
    system("chcp 1251>nul");
    int size = enter();
    LIST* List = make(size);
    cout << "Ваш список" << endl;
    print(List);
    if (size == 1)
                                                                                                                                                                 cout << "Так как в ВАШЕМ списке ОДИН эелемент, то изменять нечего ахазазазззаззахахазахзхаз" << endl;
    else
    {
        cout << "Изменённый список :" << endl;
        Remove(List);
    }
    del(List);
    return 0;
}

