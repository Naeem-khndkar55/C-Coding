#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        tot += p;
        v[i] = tot;
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
