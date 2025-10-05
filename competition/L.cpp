#include <iostream>

using namespace std;

int main()
{
    int c;

    cin >> c;
    int a, b;

    for (int i = 0; i < c; i++)
    {
        cin >> a;
        cin >> b;
        int result = 14 - (a + b);

        cout << result << endl; 
    }

    return 0;
}