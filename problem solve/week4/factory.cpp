#include <vector>
#include <iostream>
#include <list>
#include <utility>
using namespace std;
void find_levels(vector<int> &warehouse , vector<int> *adj,int *levels,int n)
{
  list<int> next_level;
  for (int i = 0; i < warehouse.size(); i++)
  {
        bool seen[n];
        fill(seen,seen+n,false);
        int pos = warehouse[i];
        next_level.push_back(pos);
        levels[pos] = 0;
        while(! next_level.empty()) {
            list<int> current_level = next_level;
            next_level.clear();
            for(auto i = current_level.begin();
                i != current_level.end(); i++) {
                int u = *i;
                seen[u] = true;
                for(auto j = adj[u].begin();
                    j != adj[u].end(); j++) {
                    int v = *j;
                    if(!seen[v]){ 
                        if(levels[u]+1 < levels[v])
                            levels[v] = levels[u] + 1;
                    next_level.push_back(*j);
                    }
                }
            }
        }
  }

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
    find_levels(warehouse,adj,levels,n);
    for (int i = 0; i < t; i++)
    {
        cout<<levels[factory[i]]<<"\n";
    }
    

}