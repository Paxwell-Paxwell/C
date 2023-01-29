#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int dismax = 1000000000;
struct edge{
    int target;
    int weight;
    int sp;
};
struct Compareedge {
    bool operator() (const edge &a, const edge &b) {
        return a.weight > b.weight;
    }
};
struct specialedge {
    int from;
    int to;
    int weight;
};
vector<edge> adj[100001];
vector <specialedge> pathspecial;
int shortestpath(edge start,int n){
    bool visited[100001] ;
    int parent[100001];
    fill(visited,visited+n,false);
    int dist[100001] ; 
    fill(dist,dist+n,dismax);
    priority_queue<edge, vector<edge >, Compareedge> pq;
    pq.push(start);
    dist[start.target] = 0;
    int u;
    while(!pq.empty()){
        u = pq.top().target;
        pq.pop();
        visited[u] = true; 
        for (auto v: adj[u])
        {
            if(!visited[v.target]&&dist[v.target]>(dist[u]+v.weight))
            {
                dist[v.target] = dist[u]+v.weight;
                edge n_target ={v.target,dist[v.target],v.sp};
                pq.push(n_target);
            }
        }
    }
    return dist[n-1];
}
int shortestpathsSp(edge start,int n,specialedge spe){
    int dist[100001] ; 
    bool visited[100001] ;
    fill(visited,visited+n,false);
    fill(dist,dist+n,dismax);
    priority_queue<edge, vector<edge >, Compareedge> pq;
    pq.push(start);
    dist[start.target] = 0;
    while(!pq.empty()){
        int u = pq.top().target;
        pq.pop();
        visited[u] = true; 
        for (auto v: adj[u])
        {
            if(!visited[v.target]&&dist[v.target]>(dist[u]+v.weight))
            {
                if(v.sp==1&&(u!=spe.from||v.target!=spe.to||v.weight!=spe.weight))   continue;
                dist[v.target] = dist[u]+v.weight;
                edge n_target ={v.target,dist[v.target],v.sp};
                pq.push(n_target);
            }
        }
    }
    return dist[n-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    int u,v,w,sp;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>w>>sp;u--;v--; 
        edge connectV = {v,w,sp},connectU = {u,w,sp};
        adj[u].push_back(connectV);
        adj[v].push_back(connectU);
    }
    edge start = {0,0,0};
    int ah = shortestpath(start,n);
    if (pathspecial.size()<=1)
    {
        if (ah==dismax)
        {
            cout<<"-1";
        }
        else
        {
            cout<<ah;
        }
        return 0;
    }
    // for(auto i: pathspecial){
    //     cout<<"from: "<<i.from<<" "<<"to: "<<i.to<<" "<<"weight: "<<i.weight<<endl;
    // }
    int min =dismax;
    for(auto i: pathspecial){
            int temp = shortestpathsSp(start,n,i);
            if(temp<min) min = temp;
    }
        if (min==dismax)
            {
                cout<<"-1";
            }
        else
            {
                cout<<min;
            }
    return 0;
}
