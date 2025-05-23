#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
ll n, m;
ll ans = INT_MAX;
ll col[100];
ll par[100];
ll hi = 200;
vector<ll> adj[100], bestCycle;
void sort(vector<ll> &bestCycle)
{
    ll sg = bestCycle.size();
    for (ll i = 0; i < sg - 1; i++)
    {
        for (ll j = 0; j < sg - i - 1; j++)
        {
            if (bestCycle[j] > bestCycle[j + 1])
            {
                swap(bestCycle[j], bestCycle[j + 1]);
            }
        }
    }
}
void dfs(ll u)
{
    col[u] = 1;
    for (auto v : adj[u])
    {
        if (col[v] == 1)
        {
            ll sum = 0;
            vector<ll> cycle = {v};
            for (ll i = u; i != v; i = par[i])
            {
                sum += i;
                cycle.push_back(i);
            }
            if (sum < hi)
            {
                hi = sum;
                bestCycle = cycle;
            }
        }
        else
        {
            par[v] = u;
            dfs(v);
        }
    }
    col[u] = 2;
}
int main()
{
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (col[i] != 2)
        {
            dfs(i);
        }
    }
    sort(bestCycle);
    for (auto i : bestCycle)
    {
        cout << i << " ";
    }
    cout << endl;
}