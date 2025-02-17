#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
ll n, x[12], y[12], p, q, ans;
void dist(ll i, vector<ll> &v, ll z)
{
    v[i] = 1;
    ll c = 1;
    for (ll j = 1; j <= n; j++)
    {
        if (v[j] == 0)
        {
            c = 0;
            dist(j, v, z + abs(x[i] - x[j]) + abs(y[i] - y[j]));
            v[j] = 0;
        }
    }
    if (c)
    {
        z += abs(x[i] - p) + abs(y[i] - q);
        ans = min(ans, z);
    }
}
int main()
{

    ll t;
    // cin>>t;
    for (ll cs = 1; cs <= 10; cs++)
    {
        cin >> n >> x[0] >> y[0] >> p >> q;
        for (ll i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
        }
        ans = INT_MAX;
        vector<ll> v(n + 1, 0);
        dist(0, v, 0);
        cout << "#" << cs << " " << ans << endl;
    }
    return 0;
}
