#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> computePrefixFunction(const string &s)
{
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int main()
{

    string s;
    cin >> s;
    int n = s.length();
    vector<int> pi = computePrefixFunction(s);
    vector<int> borders;

    int j = pi[n - 1];
    while (j > 0)
    {
        borders.push_back(j);
        j = pi[j - 1];
    }

    reverse(borders.begin(), borders.end());
    for (int len : borders)
    {
        cout << len << " ";
    }

    return 0;
}
