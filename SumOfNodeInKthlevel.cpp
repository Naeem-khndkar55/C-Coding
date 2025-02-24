#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 22 + 10;
ll n;
ll sum;
ll ans = INT_MAX;
int tonum(string x)
{
    int num = 0;
    for (size_t i = 0; i < x.size(); i++)
    {
        num = num * 10 + (int(x[i]) - 48);
    }
    return num;
}
int main()
{
    cin >> n;
    string s;
    cin >> s;
    sum = 0;
    ll level = -1;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            level++;
        }
        else if (s[i] == ')')
        {
            level--;
        }
        else if (level == n)
        {
            string tmp;
            while (i < s.size() && s[i] != '(' && s[i] != ')')
            {
                tmp.push_back(s[i]);
                i++;
            }
            i--;
            sum += tonum(tmp);
        }
    }
    cout << sum << endl;
    return 0;
}