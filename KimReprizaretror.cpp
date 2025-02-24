#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;
ll ans;
ll x[20], y[20];
ll arr[20][20];
bool vis[20] = {false};
ll p, q, n;
void dist(ll k, ll cnt, ll val)
{
    if (cnt == n)
    {
        val += arr[k][n + 1];
        ans = min(ans, val);
        return;
    }
    vis[k] = true;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dist(i, cnt + 1, val + arr[k][i]);
        }
    }
    vis[k] = false;
}
int main()
{
    for (ll t = 1; t <= 10; t++)
    {
        cin >> n >> x[0] >> y[0] >> p >> q;
        for (ll i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
        }
        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= n; j++)
            {
                arr[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        x[n + 1] = p;
        y[n + 1] = q;
        for (ll i = 0; i <= n; i++)
        {
            arr[i][n + 1] = abs(x[i] - p) + abs(y[i] - q);
        }
        ans = INT_MAX;
        dist(0, 0, 0);
        cout << "#" << " " << t << " " << ans << endl;
    }
}