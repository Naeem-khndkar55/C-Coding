#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
ll n;
ll arr[15][15];
ll ans = INT_MAX;
bool vis[100] = {false};
int dist(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}
void wormhole(ll sx, ll sy, ll dx, ll dy, ll val)
{
    ans = min(ans, val + dist(sx, sy, dx, dy));
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;

            wormhole(arr[i][2], arr[i][3], dx, dy, val + dist(sx, sy, arr[i][0], arr[i][1]) + arr[i][4]);
            wormhole(arr[i][0], arr[i][1], dx, dy, val + dist(sx, sy, arr[i][2], arr[i][3]) + arr[i][4]);

            vis[i] = false;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }
        ans = INT_MAX;
        wormhole(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
}