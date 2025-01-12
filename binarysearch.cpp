#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int BinarySearch(vector<ll> v, ll s, ll e, ll k)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;
    if (v[mid] == k)
    {
        return mid;
    }

    else if (v[mid] > k)
    {
        return BinarySearch(v, s, mid - 1, k);
    }
    else
    {
        return BinarySearch(v, mid + 1, e, k);
    }
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll bs = BinarySearch(v, 0, n - 1, k);
    cout << bs << endl;
}
