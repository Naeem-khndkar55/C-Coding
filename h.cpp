#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    map<string, int> mp;
    ll t;
    cin >> t;

    while (t--)
    {
        ll op;
        cin >> op;

        if (op == 0)
        {
            string key;
            ll val;
            cin >> key >> val;
            mp[key] = val;
        }
        else if (op == 1)
        {
            string key;
            cin >> key;
            if (mp.find(key) != mp.end())
            {
                cout << mp[key] << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (op == 2)
        {
            string key;
            cin >> key;
            mp.erase(key);
        }
        else if (op == 3)
        {
            string L, R;
            cin >> L >> R;
            auto low = mp.lower_bound(L);
            auto high = mp.upper_bound(R);
            for (auto i = low; i != high; ++i)
            {
                cout << i->first << " " << i->second << endl;
            }
        }
    }

    return 0;
}