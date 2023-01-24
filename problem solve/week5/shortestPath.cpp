
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int dismax = 1000000000;
bool visited[100010] ={false};
struct ComparePairSecond {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};
//find shortest path from start to end
int shortestpath(pair<int,int> start, vector<pair<int,int> > *graph,int n){
    int short_dis[n] ;
    fill(short_dis,short_dis+n,dismax);
    priority_queue<pair<int, int>, vector<pair<int, int> >, ComparePairSecond> pq;
    pq.push(start);
    short_dis[start.first] = 0;
    int u,dist;
    while(!pq.empty()){
        int u = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        visited[u] = true; 
        for (auto v: graph[u])
        {
            if(!visited[v.first]&&short_dis[v.first]>(short_dis[u]+v.second))
            {
                short_dis[v.first] = short_dis[u]+v.second;
                pq.push(make_pair(v.first,short_dis[v.first]));
            }
        }
    }
    return short_dis[n-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > graph[n];//{tonode,weight}
    int u,v,w;
    for(int i = 0; i < m; i++)
    {

        cin>>u>>v>>w;
        u--;v--;
        
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    int sh = shortestpath(make_pair(0,0),graph,n);
    cout<<sh;
    
}