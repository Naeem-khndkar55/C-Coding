#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Graph
{
    int V;
    list<int> *lst; // defining a dynamic array ex:int *arr
public:
    Graph(int V)
    {
        this->V = V;
        lst = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        lst[x].push_back(y);
        lst[y].push_back(x);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    return 0;
}