#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 22 + 10;
ll n;
ll arr[N];
ll func(ll start, ll stop)
{
    if (start > stop)
    {
        return 0;
    }
    ll ans = INT_MIN;
    for (int i = start; i <= stop; i++)
    {
        ll tmp = 0;
        if (start == 1 && stop == n)
        {
            tmp = arr[i] + func(1, i - 1) + func(i + 1, n);
        }
        else
        {

            tmp = arr[start - 1] * arr[stop + 1] + func(start, i - 1) + func(i + 1, stop);
        }
        ans = max(ans, tmp);
    }
    return ans;
}
int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[0] = arr[n + 1] = 1;

    ll ans = func(1, n);
    cout << ans << endl;
}