#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define M = 100000000 + 7;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll m = 100000000 + 7;

        if ((n % m) % 3 == 0)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {

            ll p = (n % m) % 3;
            if (p == 2)
            {
                cout << 1 << " " << 2 << endl;
            }
            else
            {
                cout << 2 << " " << 1 << endl;
            }
        }
    }
}
