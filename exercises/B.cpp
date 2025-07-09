#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;

    for (int i = 0; i < 3; i++)
    {
        if (A % 10 == 7)
        {
            cout << "Yes";
            return 0;
        }
        A = A / 10;
    }

    cout << "No";

    return 0;
}