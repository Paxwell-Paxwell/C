
#include <vector>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

void find_levels(int pos , vector<int> *adj,int *levels,int *ch_bi)
{
  list<int> next_level;
  next_level.push_back(pos);
  levels[pos] = 0;
  
  while(! next_level.empty()) {
    list<int> current_level = next_level;
    next_level.clear();
    for(auto i = current_level.begin();
        i != current_level.end(); i++) {
        int u = *i;
      
      for(auto j = adj[u].begin();
          j != adj[u].end(); j++) {
        int v = *j;
        if(levels[v]==levels[u]){
            *ch_bi = 0;
            return;
        }

        if(levels[v] == -1) {
          levels[v] = levels[u] + 1;
          next_level.push_back(*j);
        }
      }
    }
  }
}
int main(){  
    int k;
    vector<int> ans;
    cin>>k;
    for(int j=0;j<k;j++){
        int n,m;
        cin>>n>>m;
        vector<int>  adj[n];
        int levels[n];
        fill(levels,levels+n,-1);
        int ch_bi =1;
        int u,v;
        int start;
        for(int i=0;i<m;i++){
        cin>>u>>v;u--;v--;
        if(i==0)
                start = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        find_levels(start,adj,levels,&ch_bi);
        ans.push_back(ch_bi);
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i])
            cout<<"yes"<<"\n";
        else
            cout<<"no"<<"\n";
    }
}
