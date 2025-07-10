#include <iostream>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    string elements[H];

    for (int i = 0; i < H; i++)
    {
        cin >> elements[i];
    }

    int sum = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if(elements[i][j] == '#'){
                sum++;
            }
        }
        
    }
    cout << sum;
    return 0;
}