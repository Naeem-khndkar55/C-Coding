#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
int arr[15][15];
int b[15][15];
int boom(int x, int y)
{
    if (x < 1 || y < 1 || y > 5)
    {
        return 0;
    }
    int p = 0, q = 0, r = 0;
    if (b[x][y] == 1)
    {
        p = 1 + boom(x - 1, y - 1);
        q = 1 + boom(x - 1, y + 1);
        r = 1 + boom(x - 1, y);
    }
    else if (b[x][y] == 0)
    {
        p = boom(x - 1, y - 1);
        q = boom(x - 1, y + 1);
        r = boom(x - 1, y);
    }
    return max(max(p, q), r);
}
int main()
{
    int t;
    cin >> t;

    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        for (ll i = 1; i <= n + 1; i++)
        {
            for (ll j = 1; j <= 5; j++)
            {
                arr[i][j] = 0;
                b[i][j] = 0;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= 5; j++)
            {
                cin >> arr[i][j];
                b[i][j] = arr[i][j];
            }
        }
        int ind = n;
        int ans = 0;
        while (ind > 0)
        {
            for (int i = ind; i > max(ind - 5, 0); i--)
            {
                for (int j = 1; j <= 5; j++)
                {
                    if (b[i][j] == 2)
                    {
                        b[i][j] = 0;
                    }
                }
            }
            ans = max(ans, boom(n + 1, 3));
            for (int i = ind; i > max(ind - 5, 0); i--)
            {
                for (ll j = 1; j <= 5; j++)
                {
                    b[i][j] = arr[i][j];
                }
            }
            ind--;
        }
        cout << "#" << k << " " << ans << endl;
    }
}