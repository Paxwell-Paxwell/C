#include <vector>
#include <iostream>
#include <list>
using namespace std;
void find_levels(vector<int> &warehouse , vector<int> *adj,int *levels,int n)
{
  list<int> Q;
  for (int i = 0; i < warehouse.size(); i++)
  {
        bool seen[n];
        fill(seen,seen+n,false);
        Q.push_back(warehouse[i]);
        seen[warehouse[i]] = true;
        levels[warehouse[i]] = 0;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop_front();
            for(int d=0; d<adj[u].size(); d++) {
                int v = adj[u][d];
                if(!seen[v]) {
                    Q.push_back(v);
                    seen[v] = true;
                    if(levels[u]+1 < levels[v])
                        levels[v] = levels[u] + 1;
                }
            }
                
        }
    }
 }
vector<int> find_levels_factory(vector<int> &factory ,vector<int> &warehouse, vector<int> *adj,int n)
{
    int levels[n];
    fill(levels,levels+n,1000000000);
    list<int> Q;
    vector<int> ans;
    for (int i = 0; i < factory.size(); i++)
    {
        bool seen[n];
        fill(seen,seen+n,false);
        Q.push_back(factory[i]);
        seen[factory[i]] = true;
        levels[factory[i]] = 0;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop_front();
            for(int d=0; d<adj[u].size(); d++) {
                int v = adj[u][d];
                if(!seen[v]) {
                    Q.push_back(v);
                    seen[v] = true;
                    levels[v] = levels[u] + 1;
                }
            }
                
        }
        int min = 1000000000;
        for (int i = 0; i < warehouse.size(); i++)
            {
                if(levels[warehouse[i]] < min)
                    min = levels[warehouse[i]];
            }
        ans.push_back(min);
    }
    return ans;
}
int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<int> adj[n];
    int levels[n];
    fill(levels,levels+n,1000000000);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> warehouse,factory;
    for(int i=0;i<s;i++){
        cin>>u;u--;
        warehouse.push_back(u);
    }
    for(int i=0;i<t;i++){
        cin>>u;u--;
        factory.push_back(u);
    }
    if(s<=5){
        find_levels(warehouse,adj,levels,n);
        for (int i = 0; i < t; i++)
        {
            cout<<levels[factory[i]]<<"\n";
        }
    }
    else{
        vector<int> ans = find_levels_factory(factory,warehouse,adj,n);
        for (int i = 0; i < t; i++)
        {
            cout<<ans[i]<<"\n";
        }
    }
    return 0;
}