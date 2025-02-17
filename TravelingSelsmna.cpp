#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll arr[100][100];
ll vis[100];
ll ans;
ll n;

void backtrack(ll k, ll count, ll sum)
{
    if (count + 1 == n)
    {
        sum += arr[k][0]; // Return to start
        ans = min(ans, sum);
        return;
    }

    vis[k] = 1;
    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            backtrack(i, count + 1, sum + arr[k][i]);
        }
    }
    vis[k] = 0; // Backtrack
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 0 << endl; // Edge case for one city
            continue;
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        ans = 1e9 + 7;
        backtrack(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
