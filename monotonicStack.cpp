#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> monotonicStack(vector<ll> &v) // increasing stack;
{
    stack<ll> st;

    ll n = v.size();
    vector<ll> res(n);
    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > v[i]) // if for decreasing stack st.top()<v[i];
        {
            st.pop();
        }

        // for decreasing stack

        // if(!st.top()){
        //     res[i]=st.top();
        // }else{res[i]=-1}
        st.push(v[i]);
    }
    while (!st.empty()) // for decreasing stack this loop is not needed
    {
        res.insert(res.begin(), st.top());
        st.pop();
    }
    return res;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> res = monotonicStack(v);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}
