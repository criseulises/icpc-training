#include <iostream>
using namespace std;
int main()
{
    int r, c, q;

    cin >> r >> c >> q;
    int elements[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> elements[i][j];
        }
    }

    int typeQ = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> typeQ;
        if (typeQ == 3)
        {
            int a, b;
            cin >> a >> b;
            cout << elements[a - 1][b - 1] << endl;
        }
        else if (typeQ == 1)
        {
            int a;
            cin >> a;
            for (int k = 0; k < c / 2; k++)
            {
                swap(elements[a - 1][k], elements[a - 1][c - 1 - k]);
            }
        }
        else if (typeQ == 2)
        {
            int b;
            cin >> b;
            for (int k = 0; k < r / 2; k++)
            {
                swap(elements[k][b - 1], elements[r - 1 - k][b - 1]);
            }
        }
    }

    return 0;
}