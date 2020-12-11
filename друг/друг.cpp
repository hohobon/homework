#include <iostream>
#include <math.h>
#include <cmath>




//y = 3x - 4ln(x) - 5 = 0
//[2,4]
//Точное значение : 3,2300

using namespace std;

int main()
{

    setlocale(LC_ALL, "Ru");

    double e;
    e = 0.1;


    double a = 2;

    double b = 4;
    double fx0;
    double fa;
    double fb;


    double x01;
    double x02;
    bool zero = 0;
    x01 = (((b - a) / 2) + a);
    cout << "x01  = " << x01 << endl;
    fx0 = 3 * x01 - 4 * log(x01) - 5;
    cout << "fx0 = " << fx0 << endl;

    fa = 3 * a - 4 * log(a) - 5;
    cout << "fa = " << fa << endl;

    fb = 3 * b - 4 * log(b) - 5;
    cout << "fb = " << fb << endl;

    if (fb * fx0 < 0)
    {
        a = x01;
        cout << "new a  =  " << a << endl;
    }
    else if (fa * fx0 < 0)
    {
        b = x01;
        cout << "new b  =  " << b << endl;
    }


    


    do
    {
        x02 = x01;
        x01 = (b - a) / 2 + a;
        cout << "x01  = " << x01 << endl;

        cout << "x0 = " << x01 << endl;

        fx0 = 3 * x01 - 4 * log(x01) - 5;
        cout << "fx0 = " << fx0 << endl;

        fa = 3 * a - 4 * log(a) - 5;
        cout << "fa = " << fa << endl;

        fb = 3 * b - 4 * log(b) - 5;
        cout << "fb = " << fb << endl;

        if (fb * fx0 < 0)
        {
            a = x01;
            cout << "new a  =  " << a;
        }
        else if (fa * fx0 < 0)
        {
            b = x01;
            cout << "new b  =  " << b;
        }
        else {
            zero = 1;
        }

        cout << "x01  =" << x01 << "  " << "x02" << x02 << endl;
    } while (abs(x02 - x01) > e) ;
    return 0;
    cout << x01;
}