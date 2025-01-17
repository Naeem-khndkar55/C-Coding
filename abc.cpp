#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll p = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            if (i > 0)
            {
                ll x = ((m - x) + (m - y)) * 2;
                p += x;
            }
        }
        ll q = (4 * m) * n;
        ll ans = p - p;
        cout << ans << endl;
    }
}
