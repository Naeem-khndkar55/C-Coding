#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
ll arr[15][15];
bool vis[15][15];
ll n, m;
ll ans;
void slove(ll x, ll y, ll val)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return;
    }
    if (arr[x][y] == 3)
    {
        ans = min(ans, val);
        return;
    }
    vis[x][y] = true;
    int up = x - 1;
    while (arr[up][y] == 0 && up >= 0)
    {
        up--;
    }
    if (up >= 0 && vis[up][y] == false)
    {
        slove(up, y, max(val, x - up));
    }
    int down = x + 1;
    while (arr[down][y] == 0 && down < n)
    {
        down++;
    }
    if (down < n && vis[down][y] == false)
    {
        slove(down, y, max(val, down - x));
    }
    if (arr[x][y + 1] != 0 && vis[x][y + 1] == false && y + 1 < m)
    {
        slove(x, y + 1, val);
    }
    if (arr[x][y - 1] != 0 && vis[x][y - 1] == false && y - 1 >= 0)
    {
        slove(x, y - 1, val);
    }
    vis[x][y] = false;
}
int main()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (ll i = 0; i < 15; i++)
    {
        for (ll j = 0; j < 15; j++)
        {
            vis[i][j] = false;
        }
    }
    ans = 100;
    slove(n - 1, 0, 0);
    cout << ans << endl;
}