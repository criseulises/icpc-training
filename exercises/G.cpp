#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int numbers[T];
    string cases[T];
    for (int i = 0; i < T; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < T; i++)
    {
        int palindrome = 0;
        int currentNumber = numbers[i];
        while (currentNumber != 0)
        {
            palindrome = currentNumber % 10 + palindrome * 10;
            currentNumber /= 10;
        }

        if (numbers[i] == palindrome)
        {
            cases[i] = "Case " + to_string(i + 1) + ": Yes";
        }
        else
        {
            cases[i] = "Case " + to_string(i + 1) + ": No";
        }
    }

    for (int i = 0; i < T; i++)
    {
        cout << cases[i] << '\n';
    }
}