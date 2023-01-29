#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
vector<int> adj[1001];
int n,m,h;
int find_levels(int start)
{
    list<int> Q;
    int count=0;
    int levels[n];
    bool seen[n];
    fill(seen,seen+n,false);
    Q.push_back(start);
    count++;
    seen[start] = true;
    levels[start] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<adj[u].size(); d++) {
                int v = adj[u][d];
                if(!seen[v]) {
                    Q.push_back(v);
                    seen[v] = true;
                    levels[v] = levels[u] + 1;
                    if(levels[v]>h){
                        return count;
                    }
                    count++;
                }
            }
    }   
    return count;  
 }
 
 void readInput(){
    cin >> n >> m >> h;
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 }
int main(){
    readInput();
    int max_save = 0;
    for (int i = 0; i < n; i++)
    {
        max_save = max(max_save,find_levels(i));
    }
    cout<<max_save<<"\n";
}