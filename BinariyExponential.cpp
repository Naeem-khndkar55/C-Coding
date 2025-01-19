#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll BinaryExponentiation(ll b, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    ll res = BinaryExponentiation(b, p / 2);
    if (p % 2)
    {
        return res * res * b;
    }
    else
    {
        return res * res;
    }
}
int main()
{
    ll base, pow;
    cin >> base >> pow;
    ll ans = BinaryExponentiation(base, pow);
    cout << ans << endl;
}
