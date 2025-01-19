#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N + 1];
int vis[N + 1];
typedef long long ll;
void dfs(int node)
{
    vis[node] = 1;
    cout << node << " ";
    for (auto i : g[node])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
}