#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int node, vector<int> g[], int vis[])
{
    vis[node] = 1;
    cout << node << " ";
    for (auto i : g[node])
    {
        if (!vis[i])
        {
            dfs(i, g, vis);
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    int vis[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, g, vis);
}