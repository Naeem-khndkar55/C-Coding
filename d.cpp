#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll lower = (n / 100) * 100 - 1;
    if (lower < 0)
        lower = 99;

    ll upper = (n / 100 + 1) * 100 - 1;

    if (lower % 100 != 99)
    {
        lower = (n / 100 - 1) * 100 + 99;
    }
    if (upper % 100 != 99)
    {
        upper = (n / 100) * 100 + 99;
    }

    ll low_dist = abs(n - lower);
    ll high_dist = abs(upper - n);

    if (low_dist < high_dist)
    {
        cout << lower << endl;
    }
    else if (high_dist < low_dist)
    {
        cout << upper << endl;
    }
    else
    {

        cout << max(lower, upper) << endl;
    }

    return 0;
}