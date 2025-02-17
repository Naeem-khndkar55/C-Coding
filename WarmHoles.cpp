#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

ll n;
ll arr[10][5];
bool vis[10] = {false};
ll ans;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

void solve(ll sx, ll sy, ll dx, ll dy, ll val)
{
    ans = min(ans, val + dist(sx, sy, dx, dy));

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            solve(arr[i][0], arr[i][1], dx, dy, val + dist(sx, sy, arr[i][2], arr[i][3]) + arr[i][4]);
            solve(arr[i][2], arr[i][3], dx, dy, val + dist(sx, sy, arr[i][0], arr[i][1]) + arr[i][4]);
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
        cin >> sx >> sy >> dx >> dy; // Read starting and destination coordinates

        ans = 1e9 + 7; // Initialize ans properly
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }

        solve(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
    return 0;
}
