#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll m = n;

    string x = to_string(n);
    ll p = x.size();
    ll ans = 0;
    while (n > 0)
    {
        ll a = n % 10;
        ll b = pow(a, p);
        ans += b;
        n /= 10;
    }
    if (ans == m)
    {
        cout << "Armstrong number" << endl;
    }
    else
    {
        cout << "Sorry! not Armstrong Number" << endl;
    }
}
