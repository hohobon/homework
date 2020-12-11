#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int N, a, b, min, max;
    cout << "Введит размер массива" << endl;
    cin >> N;
    while (N < 0)
    {
        cout << "Размер массива не мот быть отрицательным" << endl;
        cin >> N;
    }
    cout << "Размер массива = " << N << endl;
    cout << " Задайте диапозон допустимвх чисел для заполнеия массивов: " << endl;
    cout << "min = ";
    cin >> min;
    cout << "\n";
    cout << "max = ";
    cin>> max;
    cout << "\n";
    while (min > max)
    {
        cout << "Минимальное значение не может быть больше максимального" << endl;
        cout << "min = ";
        cin >> min;
        cout << "\n";
        cout << "max = ";
        cin >> max;
        cout << "\n";
    }
    int* array = new int[N];
    for(int i = 0; i < N; i++)// Заполнение массива случайными числами
    {
        array[i] = min + rand() % max;
        cout << "array[" << i << "] = " << array[i] << endl;
    }
   
    
    cout << "номер удалемого элемента = ";
    cin >> a;
    cout << "\n";
    while ((a >= N) || (a < 0))
    {
        cout << "Номер элемента должен быть на промежутке 0 < a < " << N - 1;
        cin >> a;
    }
    int a1 = a;
    cout << "\n Сдвиг элемента" << endl;
    for (int i = 0; i < N - a; i++)    
    {
        array[a1] = array[a1 + 1];
        a1++;
    }
    cout << "\n массив с удаленным числом" << endl;
    for (int i = 0; i < N-1 ; i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
    
    bool flag = 0;
    int i = 0;
    while ((flag == 0) && (i < N - 1))
    {
        if (array[i] % 2 == 0)
        {
            b = i;
            flag = 1;
        }
        else i++;
    }
    if (flag == 0)
    {
        cout << "Четных чисел не встретилоь :(";
            return 0;
    }
    for (int i = 0; i < N - b; i++)
    {
        array[N-i] = array[N-i-1];
    }
    array[b] = array[b - 1] + 2;
    cout << "вывод массива со вставлннным элементом по правилу : после первого четного элемента массива элемент со значением M[I - 1] + 2." << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
    return 0;
}


