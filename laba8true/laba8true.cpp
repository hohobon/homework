#include <string>
#include <iostream>
using namespace std;
struct pupil
{
    string telnum;
    string  name;
    int clas = 0;
    int math = 0;
    int phys = 0 ;
    int rus = 0;
    int lang = 0;
    int liter = 0;
};
void fill(pupil* a, int b)
{
    for (int i = 0; i < b; i++)
    {
        cout << "Ученик № " << i + 1 << endl;
        cout << "Ф.И.О. : "; cin.ignore(); getline(cin, a[i].name); cout << endl;
        cout << "номер класса : "; cin >> a[i].clas;    cout << endl;
        while ((a[i].clas < 1) || (a[i].clas > 11))
        {
            cout << "Введен некoректный номер класса (1-11)" << endl;
            cin >> a[i].clas;
        }
        cout << endl;
        cout << "номер телефона : "; cin.ignore(); getline(cin, a[i].telnum);  cout << endl;
        cout << "Математика : ";  cin >> a[i].math;  cout << endl;
        while ((a[i].math < 2) || (a[i].math > 5))
        {
            cout << "Введен некoректная оценка (2 - 5)" << endl;
            cin >> a[i].math;
        }
        cout << "Физика : ";  cin >> a[i].phys;  cout << endl;
        while ((a[i].phys < 2) || (a[i].phys > 5))
        {
            cout << "Введен некoректная оценка (2 - 5)" << endl;
            cin >> a[i].phys;
        }
        cout << "Русский язык : "; cin >> a[i].rus;  cout << endl;
        while ((a[i].rus < 2) || (a[i].rus > 5))
        {
            cout << "Введен некoректная оценка (2 - 5)" << endl;
            cin >> a[i].rus;
        }
        cout << "Иностранный язык : ";  cin >> a[i].lang; cout << endl;
        while ((a[i].lang < 2) || (a[i].lang > 5))
        {
            cout << "Введен некoректная оценка (2 - 5)" << endl;
            cin >> a[i].lang;
        }
        cout << "Литература : ";    cin >> a[i].liter;   cout << endl;
        while ((a[i].liter < 2) || (a[i].liter > 5))
        {
            cout << "Введен некoректная оценка (2 - 5)" << endl;
            cin >> a[i].liter;
        }
    }
}
void show(pupil * a, int b)
{
   
   for (int i = 0; i < b; i++)
   {
        cout << "ФИО :" << a[i].name << endl;
        cout << "Класс :" << a[i].clas << endl;
        cout << "Номер телефона :" << a[i].telnum << endl;
        cout << "Математика :" << a[i].math << endl;
        cout << "Физика :" << a[i].phys << endl;
        cout << "Русский язык :" << a[i].rus << endl;
        cout << "Иностранный язык :" << a[i].lang << endl;
        cout << "Литература :" << a[i].liter << endl;
        cout << endl;
   }
    
}

void del(pupil* a, int* b)
{
    for (int i = 0; i < *b; i++)
    {
        if ((a[i].math == 2) || (a[i].phys == 2) || (a[i].rus == 2) || (a[i].liter == 2) || (a[i].lang == 2))
        {
            for (int j = i; j < *b - 1; j++)
            {
                a[j] = a[j + 1];
            }
            i--;
            (*b)--;
        }
    }
}

void paste(pupil*& a, int* b)
{
    pupil* c = new pupil[*b + 1];
    fill(c, 1);
    for (int i = 1; i < *b + 1; i++)
    {
        c[i] = a[i - 1];
    } 
    delete[] a;
    a = c;
    (*b) += 1;
}



int main()
{
    system("chcp 1251>nul");
    int b;
    cout << "Введите кол-во элементов структуры: ";
    cin >> b;
    while (b <= 0)
    {
        cout << "Размер не может быть отрицательным или равен нулю" << endl;
        cin >> b;
    }
    pupil* a = new pupil[b];
    fill(a, b);
    show(a, b);
    del(a, &b);
    cout << endl << "Cтруктура после удаления элементов :" << endl;
    show(a, b);
    paste(a, &b);
    cout << endl << "Cтруктура после вставки элемента :" << endl;
    show(a, b);

    return 0;
}

