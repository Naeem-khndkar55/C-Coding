#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    ll n = s.length();
    vector<int> mir;

    for (ll i = 1; i < n; i++)
    {
        bool isMir = true;
        for (ll j = 0; j < i; j++)
        {
            if (s[j] != s[n - i + j])
            {
                isMir = false;
                break;
            }
        }
        if (isMir)
        {
            mir.push_back(i);
        }
    }

    for (ll len : mir)
    {
        cout << len << " ";
    }

    return 0;
}
