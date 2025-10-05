#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        double D = 0;
        double V1 = 0;
        double V2 = 0;
        double M = 0;

        cin >> D >> V1 >> V2 >> M;

        double time = D / (V1 + V2);
        double DResult = M * time;

        cout << fixed << setprecision(2) << DResult << endl;
    }
}