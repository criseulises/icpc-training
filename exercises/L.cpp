#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int numbers[] = {0, 0};
    for (int i = 0; i < N; i++)
    {

        if(A[i] > numbers[1]){
            numbers[0] = numbers[1];
            numbers[1] = A[i];
        } else if(A[i] == numbers[1]) continue;
         else if(A[i] > numbers[0]){
            numbers[0] = A[i];
        }
    }

    cout << numbers[0]; 

    return 0;
}