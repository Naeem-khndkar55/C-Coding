#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 22 + 10;
ll n;
ll gate[5];
ll fm[5];
ll sum;
ll ans = INT_MAX;

void fisherMan(ll k, ll val, ll cnt)
{
    if (cnt == sum)
    {
        ans = min(ans, val);
        return;
    }
    if (k == n + 1)
    {
        return;
    }
    for (ll i = 0; i < 3; i++)
    {
        if (fm[i] > 0)
        {
            fm[i]--;
            fisherMan(k + 1, val + abs(gate[i] - k) + 1, cnt + 1);
            fm[i]++;
        }
    }
    fisherMan(k + 1, val, cnt);
}

int main()
{
    cin >> n;
    for (ll i = 0; i < 3; i++)
    {
        cin >> gate[i];
    }
    for (ll i = 0; i < 3; i++)
    {
        cin >> fm[i];
        sum += fm[i];
    }
    fisherMan(1, 0, 0);
    cout << ans << endl;
}