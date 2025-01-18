#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char, ll> br = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
string balacedBracket(string x)
{
    stack<char> st;
    for (char b : x)
    {
        if (br[b] < 0)
        {
            st.push(b);
        }
        else
        {
            if (st.empty())
            {
                return "NO";
            }
            char val = st.top();
            st.pop();
            if (br[val] + br[b] != 0)
            {
                return "NO";
            }
        }
    }
    if (!st.empty())
    {
        return "NO";
    }
    return "YES";
}
int main()
{
    string x;
    cin >> x;
    string ans = balacedBracket(x);
    cout << ans << endl;
}
