#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <utility>
using namespace std;
vector<pair<int,int>> adj[100001];
int n,m,k,h;
vector<int> magic;
int magic1= 0;
unordered_set<int> bfs_magic(int hp,int start){
    list<int> Q;
    int levels[n];
    bool seen[n];
    unordered_set<int> visited;
    fill(seen,seen+n,false);
    Q.push_back(start);
    seen[start] = true;
    levels[start] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<adj[u].size(); d++) {
                int v = adj[u][d].first;
                if(!seen[v]) {
                    Q.push_back(v);
                    levels[v] = levels[u] + 1;
                    if(hp-levels[v]<0){
                        return visited;
                    }
                    seen[v] = true;
                    visited.insert(v);
                    
                }
            }
    }   

    // for(auto i:visited){
    //     cout<<"visited--> "<<i+1<<"\n";
    // }
    
    return visited;  
 }
int Bfs(int start,int hp)
{
    list<int> Q;
    int levels[n];
    bool seen[n];
    fill(seen,seen+n,false);
    Q.push_back(start);
    seen[start] = true;
    levels[start] = 0;
    int out=0;
    unordered_set<int> vi_with_magic;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<adj[u].size(); d++) {
                int v = adj[u][d].first;
                if(!seen[v]) {
                    if(adj[u][d].second&&!magic1) continue;
                    Q.push_back(v);
                    levels[v] = levels[u] + 1;
                    if(levels[v]>hp){
                        out = 1;
                        break;
                    }
                    seen[v] = true;
                    if(!magic1&&find(magic.begin(), magic.end(), v+1) != magic.end()){
                        //cout<<"magic--> "<<v<<"\n";
                        unordered_set<int> temp = bfs_magic(h-levels[v],v);
                        vi_with_magic.insert(temp.begin(), temp.end());
                    }

                }
            }
        if(out) break; 
    }   
    for(auto i:vi_with_magic){
        seen[i] = true;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(seen[i]){ 
            count++;
        }
        
    }
    return count;
 }
 
 void readInput(){
    cin >>n>>m>>k>>h;
    int magic_no;
    for (int i = 0; i < k; i++)
    {
        cin>>magic_no;
        if(magic_no==1){
            magic1 = 1;
        }
        magic.push_back(magic_no);
    }
    
    for(int i=0; i<m; i++) {
        int u,v,sp;
        cin >> u >> v>>sp;u--;v--;
        adj[u].push_back(make_pair(v,sp));
        adj[v].push_back(make_pair(u,sp));
    }
 }
int main(){
    readInput();
    cout<<Bfs(0,h);
}