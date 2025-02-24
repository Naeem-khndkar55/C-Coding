#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int arr[100][100];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cz = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                cz++;
            }
        }
        mp[cz]++;
        if ((k - cz) % 2 == 0)
        {
            ans = max(ans, mp[cz]);
        }
    }
    cout << ans << endl;
    return 0;
}