#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<vector<long long>> allSpirits;
        multiset<long long> activeX, activeY, activeZ;

        for (int j = 0; j < n; j++)
        {
            string option;
            cin >> option;

            if (option == "ADD")
            {
                long long x, y, z;
                cin >> x >> y >> z;
                allSpirits.push_back({x, y, z});

                activeX.insert(x);
                activeY.insert(y);
                activeZ.insert(z);
            }
            else if (option == "REMOVE")
            {
                int k;
                cin >> k;
                k--;

                long long x = allSpirits[k][0];
                long long y = allSpirits[k][1];
                long long z = allSpirits[k][2];

                activeX.erase(activeX.find(x));
                activeY.erase(activeY.find(y));
                activeZ.erase(activeZ.find(z));
            }

            long long surfaceArea = 0;
            if (activeX.size() > 1)
            {
                long long minX = *activeX.begin();
                long long maxX = *activeX.rbegin();
                long long minY = *activeY.begin();
                long long maxY = *activeY.rbegin();
                long long minZ = *activeZ.begin();
                long long maxZ = *activeZ.rbegin();

                long long dx = maxX - minX;
                long long dy = maxY - minY;
                long long dz = maxZ - minZ;
                surfaceArea = 2 * (dx * dy + dx * dz + dy * dz);
            }

            cout << surfaceArea << endl;
        }
    }

    return 0;
}