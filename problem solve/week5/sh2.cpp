#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_INT = 100010;
int n, m;
bool visited[MAX_INT] = {false};
vector<pair<int,int>> adj[MAX_INT]; //pair<target,weight>

void read_input()
{
    cin >> n >> m;
    int a,b,w;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b >> w;
        --a; --b;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}
int shortest_path()
{ 
    int u, dist;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,0}); //dist, current
    visited[0] = true;
    while (!Q.empty())
    {
        u = Q.top().second;
        dist = Q.top().first;
        Q.pop();
        visited[u] = true;
        if (u == n-1) return dist;
        for (auto x: adj[u])
        {
            if (!visited[x.first]) 
            {
            Q.push({x.second+dist, x.first});
            }
        }
    }
    return -1;
}
int main()
{
    read_input();
    int res = shortest_path();
    cout << res;
}