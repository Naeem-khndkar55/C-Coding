#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        ll z = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll x = 0;
        ll y = 0;
        ll c = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                x += (b[i] - a[i]);
                c++;
            }
        }
        ll ans = c * x;
        for (ll i = 0; i < n; i++)
        {
            if (ans < b[i] || ans < a[i])
            {
                cout << "YES" << endl;
                z = 1;
                break;
            }
        }
        if (z == 0)
        {
            cout << "NO" << endl;
        }
    }
}
