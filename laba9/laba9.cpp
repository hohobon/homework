#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void show(ifstream& input)
{
    if (input.is_open())
    {
        string out;
        cout << "Вывод содержимого файла :" << endl;
        while (!input.eof())
        {
            out = "";
            getline(input, out);
            cout << out << endl;
        }
        cout << endl;
    }
    else
    {
        cout <<"Файл закрыт"<<endl;
    }
}

void rowcounter(int& counter )
{
    string row;
    ifstream input;
    input.open("F1.txt");
    if (input.is_open())
    {
        while (!input.eof())
        {
            getline(input, row);
            cout << row << endl;
            counter++;
        }
        cout << "Кол-во строк: " << counter << endl;
        input.close();
    }
    else
    {
        cout << "Фаайл закрыт" << endl;
    }
}

void glcount(string text,int& countgl)
{
    string gl = "A,E,I,O,U,Y,a,e,i,o,u,y,А,а,Е,е,Ё,ё,И,и,О,о,У,у,Ы,ы,Э,э,Ю,ю,Я,я";
    int a = text.length() - 1;
    int b = gl.length() - 1;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (text[i] == gl[j])
            {
                countgl++;
            }
        }
    }
}

void copypaste(ifstream& input, ofstream& output, string row, int& countgl)
{
    output << row << endl;
    glcount(row, countgl);
}

int main()
{
    system("chcp 1251>nul");
    int counter = 0;
    int N, K, countgl;
    rowcounter(counter);
    string row;
	ifstream input;//объявление переменной для чтения
    ofstream output;//объявление перменной для записи
    input.open("F1.txt");//открытие файла для чтения
    output.open("F2.txt");//открытия файла для записи 
    if ((input.is_open()) && (output.is_open()))
    {
        cout << "Введите диапозон от N до K " << endl << "Введите N" << endl; cin >> N; // Ввод строчек с какой по какю будут записаны строки
        while ((N <= 0) || (N > counter))
        {
            cout << "N должно быть ьольше 0 и меньше " << counter << endl;
            cin >> N;
        }
        if (N == counter)
        {
            K = N;
            cout << "копирование последне строки" << endl;
        }
        else
        {
            cout << "Введите K" << endl;
            cin >> K;
        
            while ((K < N) || (K > counter))
            {
            cout << "K должно быть от " << N << "до " << counter << endl;
            cin >> K;
            }
        }
        counter = 0;
        countgl = 0;
        while (!input.eof())
        {
            getline(input, row);
            counter++;
            if ((counter >= N) && (counter <= K))
            {
                copypaste(input,output, row,countgl);
            }
        }
        input.close();
        output.close();
        cout << "Кол-во гласных: " << countgl << endl;
        input.open("F2.txt");
        show(input);
        input.close();
    }
    else
    {
        cout << "Ошибка открытия файла";
    }
    
    return 0;
}


