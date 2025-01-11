#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    ll a, b;
    cin >> a >> b;
    int p = gcd(a, b);
    cout << p << endl;
    int q = __gcd(a, b);
    cout << q << endl;
    int lcm = (a / p) * b;
    cout << lcm << endl;
}
