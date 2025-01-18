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
    int val = 50;

    // Finding lower and upper boud of val in v
    auto lb = lower_bound(v.begin(), v.end(), val); // chek the first value greater or equal of the given val;
    auto up = upper_bound(v.begin(), v.end(), val); // check the firat value that is greater of the given val;

    // check is the value exist or not in the array using binary search stl funtion;
    if (binary_search(v.begin(), v.end(), val))
        cout << val << " exists in vector";
    else
        cout << val << " does not exist";

    ll bs = BinarySearch(v, 0, n - 1, k);
    cout << bs << endl;
}
