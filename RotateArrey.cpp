#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> rt;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        rt.push_back(v[i]);
    }
    vector<ll> ans;
    for (ll i = n - k; i < n; i++)
    {
        ans.push_back(v[i]);
    }
    for (ll i = 0; i < n - k; i++)
    {
        ans.push_back(v[i]);
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    /*rotate by stl function*/
    rotate(rt.begin(), rt.begin() + (n - k), rt.end());
    for (auto i : rt)
    {
        cout << i << " ";
    }
    cout << endl;
}
