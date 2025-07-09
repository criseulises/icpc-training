#include <iostream>
using namespace std;

int main()
{
    string mainString[] = {"and", "not", "that", "the", "you"};
    int size;
    cin >> size;
    string words[size];


    for (int i = 0; i < size; i++)
    {
        cin >> words[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(words[i] == mainString[j])
            {
                cout << "Yes";
                return 0;
            }
        }
        
    }
    
    cout << "No";

    return 0;
}