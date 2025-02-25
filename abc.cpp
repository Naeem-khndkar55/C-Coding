#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int N = 22 + 10;
ll arr[100][100];
ll b[100][100];
ll n, m;
ll ans;
ll sum = INT_MAX;
bool vis[100][100];
int SumOfk(string x)
{
    ll num = 0;
    for (size_t i = 0; i < x.size(); i++)
    {
        num = num * 10 + (int(x[i]) - 48);
    }
    return num;
}
int main()
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    sum = 0;
    ll lev = -1;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            lev++;
        }
        else if (s[i] == ')')
        {
            lev--;
        }
        else if (lev == k)
        {
            string tmp;
            while (i < s.size() && s[i] != '(' && s[i] != ')')
            {
                tmp.push_back(s[i]);
                i++;
            }
            i--;
            sum += SumOfk(tmp);
        }
    }
    cout << sum << endl;
}