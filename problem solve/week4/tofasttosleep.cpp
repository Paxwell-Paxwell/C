#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
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
vector<edge> adj[100001];
int shortestpathsSp(edge start,int end,int n){
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
        if(u==end) return dist[end];
        for (auto v: adj[u])
        {
            if(!visited[v.target]&&dist[v.target]>(dist[u]+v.weight)&&v.sp!=1)
            {
                dist[v.target] = dist[u]+v.weight;
                edge n_target ={v.target,dist[v.target],v.sp};
                pq.push(n_target);
            }
        }
    }
    return dist[end];
}
int shortestpath(edge start,int n){
    bool visited[100001] ;
    fill(visited,visited+n,false);
    int dist[100001] ; 
    fill(dist,dist+n,dismax);
    priority_queue<edge, vector<edge >, Compareedge> pq;
    pq.push(start);
    dist[start.target] = 0;
    int u;
    int special_edge = 0,min_sp=dismax ,sp_go= -1;
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
                if(v.sp==1) {

                    if(sp_go !=v.target ){
                        special_edge++;
                        sp_go = v.target;
                        }
                    int sh = shortestpathsSp(start,u,n),sh2 = shortestpathsSp(v,n-1,n);
                    int temp = sh +sh2+v.weight;
                    // cout<<"start--> "<<start.target+1<<" target-->"<<u+1<<" ";
                    // cout<<"sh: "<<sh;
                    // cout<<"start--> "<<v.target+1<<" target-->"<<n<<" ";
                    // cout<<"sh2: "<<sh2<<" v.weight: "<<v.weight<<"\n";
                    if(temp>dismax) temp = dismax;
                    min_sp= min(min_sp,temp);
                }
            }
        }

    }
    //cout<<"special_edge: "<<special_edge<<"\n";
    if (special_edge==0)
    {
        return dist[n-1];
    }
    else
    {
        return min_sp;
    }
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
    if (ah==dismax)
    {
        cout<<"-1";
    }
    else
    {
        cout<<ah;
    }
}