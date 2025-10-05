#include <iostream>
using namespace std;

int main()
{
    int c;
    std::cin >> c;
    int different[c];
    int A = c * 2;

    string phrases[A];
    for (int i = 0; i < A; i++)
    {
        std::cin >> phrases[i];
    }

    for (int i = 0; i < A; i += 2)
    {
        int counter = 0;
        for (int j = 0; j < phrases[i].length(); j++)
        {
            if (phrases[i][j] != phrases[i + 1][j])
            {
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
