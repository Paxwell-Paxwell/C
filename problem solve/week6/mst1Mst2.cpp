#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 300000;
struct edge
{
    int from;
    int to;
    int weight;
};
bool cmp(edge a, edge b)
{
    return a.weight < b.weight;
}
int n, m;
edge edges[MAXN];
int parent[MAXN];
int psize[MAXN];
int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}
void union_sets(int u, int v)
{
    u = find(u);
    v = find(v);
    if (psize[u] < psize[v])
    {
        parent[u] = v;
        psize[v] += psize[u];
    }
    else
    {
        parent[v] = u;
        psize[u] += psize[v];
    }
}
void readInput()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        edges[i].from--;
        edges[i].to--;
    }
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        psize[i] = 1;
    }
}
int main()
{
    readInput();
    sort(edges, edges + m, cmp);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (find(edges[i].from) != find(edges[i].to))
        {
            ans += edges[i].weight;
            union_sets(edges[i].from, edges[i].to);
        }
    }
    cout << ans << "\n";
    return 0;
}