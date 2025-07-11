#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    string cases[T];

    for (int i = 1; i <= T; i++)
    {
        string blank;
        getline(cin, blank);

        int N;
        cin >> N;

        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            if (num > 0)
                sum += num;
        }

        cout << "Case " << i << ": " << cases[i] << endl;
    }
    
    return 0;
}