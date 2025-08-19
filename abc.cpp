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
        map<ll, ll> mp;
        ll p;
        for (ll i = 0; i < n; i++)
        {
            cin >> p;
            mp[p]++;
        }
        ll ans = 0;
        vector<pair<ll, ll>> vp;
        pair<ll, ll> par;
        for (ll)
        {
            ll a = mp[i];
            ll b = mp[i].second;
            ll z = 0;
            par.first = a;
            par.second = b;
            vp.push_back(par);
            while (a % 2 == 0)
            {
                z++;
                a = a / 2;
                mp[a]++;
            }
            ans = ans + z;
        }
        cout << ans << endl;
    }
}
