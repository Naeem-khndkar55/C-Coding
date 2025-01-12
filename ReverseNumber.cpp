#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll f = 0;
    if (n < 0)
    {
        f = 1;
    }
    string x = to_string(n);
    if (f == 1)
    {
        reverse(x.begin() + 1, x.end());
    }
    else
    {
        reverse(x.begin(), x.end());
    }
    cout << x << endl;
}
