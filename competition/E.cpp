#include <iostream>
using namespace std;

int BinarySearch(int a[], int n, int x)
{
    int lo = 0;
    int hi = n - 1;
    int steps = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        steps = steps + 1;

        if (a[mid] == x)
        {
            return steps;
        }
        else if (a[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int t;  
    cin >> t; 
    
    for (int i = 0; i < t; i++)
    {
        int n, s;
        cin >> n >> s;
        int elements[n];
        for (int j = 0; j < n; j++)
        {
            elements[j] = j;
        }

        bool first = true; 
        for (int pos = 0; pos < n; pos++)
        {
            int result = BinarySearch(elements, n, pos);
            if(result == s){
                if (!first) cout << " ";
                cout << pos;
                first = false;
            }
        }
        cout << endl;  
    }

    return 0;
}