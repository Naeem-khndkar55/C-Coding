#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e5;
int graphMat[N][N];                               // space(O(n*n));
vector<int> graphList[M + 10];                    // space[O(n+n)];
vector<pair<int, int>> WeightedgraphList[M + 10]; // for weighted graph list;
typedef long long ll;
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) // for undirected graph
    {
        ll x, y, wt;
        cin >> x >> y;
        graphMat[x][y] = 1; // wt if weight given for weighted graph
        graphMat[y][x] = 1; // wt if weight given
        graphList[x].push_back(y);
        graphList[y].push_back(x);
        // WeightedgraphList[x].push_back({y, wt}); ------for weighted graph list
        // WeightedgraphList[y].push_back({x, wt});
    }
    for (ll i = 0; i < n; i++)
    { // printing matrix;
        for (ll j = 0; j < n; j++)
        {
            cout << graphMat[i][j] << " ";
        }
        cout << endl;
    }
    // printing list;
    for (ll i = 0; i < n; i++)
    {
        cout << "list: " << i << " ";
        for (auto j : graphList[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
