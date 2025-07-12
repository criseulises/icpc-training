#include <iostream>
using namespace std;

int main()
{
    int N, S, K;

    cin >> N >> S >> K;

    int totalSpend = 0;
    for (int i = 0; i < N; i++)
    {
        int amount, quantity;
        cin >> amount >> quantity;

        totalSpend += (amount * quantity);
    }

    if(totalSpend < S) cout << (totalSpend + K);
    else cout << (totalSpend);

    
    return 0;
}