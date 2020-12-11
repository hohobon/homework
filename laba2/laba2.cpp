
#include <cstdlib>
#include <iostream>
using namespace std;

int bruh(int i, int j, int m)
{

}

int main()
{
    int m, n, matrix[20][20];
    cin >> m;
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0 + rand() % 100;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

