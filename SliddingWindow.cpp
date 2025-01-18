#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sliddingWindow(vector<ll> v, ll n, ll k)
{
    if (n < k)
    {
        return -1;
    }
    ll mxSum = 0;
    for (ll i = 0; i < k; i++)
    {
        mxSum += v[i];
    }
    ll ws = mxSum;
    for (ll i = k; i < n; i++)
    {
        ws += v[k] - v[i - k];
        mxSum = max(mxSum, ws);
    }
    return mxSum;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = sliddingWindow(v, n, k);
    cout << ans << endl;
}
