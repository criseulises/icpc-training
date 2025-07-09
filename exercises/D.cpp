#include <iostream>
using namespace std;

int main()
{
    int A;
    long int sum = 0;
    cin >> A;

    for (int i = 1; i <= A; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            continue;
        } else {
            sum += i;
        }
    }
    cout << sum;
    
    return 0;
}