#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // kaadanes algorithm is use to calculate maximum sub array sum;
    // logic is if the sum is less then zero then make the sum to=0;
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll p = INT_MIN;
    ll curSum = 0;
    for (ll i = 0; i < n; i++)
    {
        curSum += v[i];
        p = max(p, curSum);
        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    cout << p << endl;
}