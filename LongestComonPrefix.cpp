#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string longestCommonPrefix(vector<string> &arr)
{
    if (arr.empty())
        return "";

    string prefix = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        auto mismatch_pair = mismatch(prefix.begin(), prefix.end(), arr[i].begin());
        prefix = prefix.substr(0, mismatch_pair.first - prefix.begin());

        if (prefix.empty())
            return "";
    }

    return prefix;
}

int main()
{
    ll n;
    cin >> n;
    vector<string> arr;

    for (ll i = 0; i < n; i++)
    {
        string p;
        cin >> p;
        arr.push_back(p);
    }

    cout << longestCommonPrefix(arr) << endl;
    return 0;
}
