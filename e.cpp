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
        vector<ll> v(n);
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        if (mp.size() < 2)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = 0;
            ll p = INT_MIN;
            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                ans += i->second;
                if (i->second > p)
                {
                    p = i->second;
                }
            }
            ll res = ans - p;
            cout << ans << endl;
        }
    }
}