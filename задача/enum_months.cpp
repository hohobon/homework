
#include <iostream>
enum months {
    january = 1,
    february,
    march,
    april,
    may,
    june,
    jule,
    august,
    september,
    october,
    november,
    december,
};
using namespace std;

int main()
{
    int m;
    cout << "number of month" << endl;
    cin >> m;
    while ((m <= 0) || (m > 12)) 
    {
        cout << "enter THE MONTH NUMBER!" << endl;
        cin >> m;
    }
     switch (m)
     {
    case(january):
        cout << "january, february, marсh, april,may,june, jule, august,september,  october,  november, december." << endl;
            break;
    case(february):
        cout << " february, marсh, april,may,june, jule, august,september,  october,  november, december." << endl;
        break;
    case(march):
        cout << " marсh, april,may,june, jule, august,september,  october,  november, december." << endl;
        break;
    case(april):
        cout << " april,may,june, jule, august,september,  october,  november, december." << endl;
        break;
    case(may):
        cout << " may,june, jule, august,september,  october,  november, december." << endl;
        break;
    case(june):
        cout << "june, jule, august,september,  october,  november, december." << endl;
        break;
    case(jule):
        cout << " jule, august,september,  october,  november, december." << endl;
        break;
    case(august):
        cout << "  august,september,  october,  november, december." << endl;
        break;
    case(september):
        cout << " september,  october,  november, december." << endl;
        break;
    case(october):
        cout << " october,  november, december." << endl;
        break;
    case(november):
        cout << "november, december." << endl;
        break;
    case(december):
        cout << " december." << endl;
        break;
    }
    

}
