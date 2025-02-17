#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
int n, m, k;
const int mn = 1000;
char a[mn][mn];
int main()
{
    cin >> n >> m >> k;
    unordered_map<string, ll> um;
    for (ll i = 0; i < n; i++)
    {
        string s;
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            s += a[i][j];
        }
        um[s]++;
    }
    ll ans = 0;
    for (const auto [str, freq] : um)
    {
        ll cz = 0;
        for (char c : str)
        {
            if (c == '0')
            {
                cz++;
            }
        }
        if (cz <= k && (k - cz) % 2 == 0)
        {
            ans = max(ans, freq);
        }
    }
    cout << ans << endl;
    return 0;
}