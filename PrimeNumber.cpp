#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sieve(int n)
{
    vector<int> prime(n + 1, 0);
    for (ll i = 2; i * i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                prime[j] = -1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    ll n;
    cin >> n;
    sieve(n);
}