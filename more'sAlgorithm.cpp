#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // mores algorithm is use to calculate maximum frequency of an element in an array without sorting;
    // logic is if the frequency of an element  is greater then n/2 then no matter what answer will be that element;
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll freq = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = v[i];
        }
        if (v[i] == ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    cout << ans << endl;
}