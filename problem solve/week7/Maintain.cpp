#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 300;
struct edge
{
    int from;
    int to;
    int weight;
};

struct ComparePairSomeValue {
    bool operator() (const edge &a, const edge &b)  {
        return a.weight > b.weight;
    }
};
int n, m;
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
int union_sets(int u, int v)
{
    u = find(u);
    v = find(v);
    if (psize[u] < psize[v])
    {
        parent[u] = v;
        psize[v] += psize[u];
        return psize[v];
    }
    else
    {
        parent[v] = u;
        psize[u] += psize[v];
        return psize[u];
    }
}
int findMst(priority_queue<edge,vector<edge>,ComparePairSomeValue> &ed)
{
    priority_queue<edge,vector<edge>,ComparePairSomeValue> ed2 = ed;
    int ans = 0;
    int max_edge = 0;
    //cout<<"size_set: "<<ed.size()<<"\n";
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        psize[i] = 1;
    }
    while (!ed2.empty())
    {
        edge cur_edge = ed2.top();
        ed2.pop();
        //cout<<"from: "<<cur_edge.from<<" to: "<<cur_edge.to<<" weight: "<<cur_edge.weight<<"\n";
        if (find(cur_edge.from) != find(cur_edge.to))
        {
            ans += cur_edge.weight;
            max_edge = union_sets(cur_edge.from, cur_edge.to);
            if(max_edge == n)
            {
                break;
            }
            //cout<<"max_edge: "<<max_edge<<"\n";
        }
    }
    //cout<<"min_ans: "<<ans<<"\n";
    return max_edge==n?ans:-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<edge,vector<edge>,ComparePairSomeValue> ed; 
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        edge n_edge;
        cin >> n_edge.from >> n_edge.to >> n_edge.weight;
        n_edge.from--;
        n_edge.to--;
        //cout<<"from: "<<n_edge.from<<" to: "<<n_edge.to<<" weight: "<<n_edge.weight<<"\n";
        ed.push(n_edge);    
        int answer = findMst(ed);
        if(answer == -1)
        {
            cout << "-1" << "\n";
        }
        else
        {
            cout << answer << "\n";
        }
    }
    return 0;
}