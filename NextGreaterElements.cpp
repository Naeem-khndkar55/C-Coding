#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    stack<ll> s;
    vector<ll> ans(n, 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(v[i]);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
