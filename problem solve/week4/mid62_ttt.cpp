
#include <vector>
#include <iostream>
#include <list>
#include <utility>
using namespace std;

int bipartile(int start , vector<int> *adj,int n)
{
  int levels[n];
  fill(levels,levels+n,-1);
  list<int> next_level;
  next_level.push_back(start);
  levels[start] = 0;
  
  while(! next_level.empty()) {
    list<int> current_level = next_level;
    next_level.clear();
    for(auto i = current_level.begin();
        i != current_level.end(); i++) {
        int u = *i;
      
      for(auto j = adj[u].begin();j != adj[u].end(); j++) {
        int v = *j;
        if(levels[v]==levels[u]){
            return 0;
        }

        if(levels[v] == -1) {
          levels[v] = levels[u] + 1;
          next_level.push_back(*j);
        }
      }
    }
  }
  return 1;
}
void deleteEdge(int from,int to,vector<int> *adj){
    for(int i=0;i<adj[from].size();i++){
        if(adj[from][i]==to){
            adj[from].erase(adj[from].begin()+i);
            break;
        }
    }
    for(int i=0;i<adj[to].size();i++){
        if(adj[to][i]==from){
            adj[to].erase(adj[to].begin()+i);
            break;
        }
    }
}
void insertEdge(int from,int to,vector<int> *adj){
    
    adj[from].push_back(to);
    adj[to].push_back(from);
}
int main(){ 
        int n,m;
        cin>>n>>m;
        vector<pair<int,int> > edges;
        vector<int>  adj[n];
        int u,v;
        int start;
        for(int i=0;i<m;i++){
          cin>>u>>v;
          u--;v--;
          if(i==0)
                  start = u;
          edges.push_back(make_pair(u,v));
          insertEdge(u,v,adj);
        }

        int flag = 0;
        for (int i = 0; i < m; i++)
        { 
            deleteEdge(edges[i].first,edges[i].second,adj);
            flag = bipartile(start,adj,n);
            if(flag==1){
                cout<<edges[i].first+1<<" "<<edges[i].second+1<<"\n";
                break;
            }
            insertEdge(edges[i].first,edges[i].second,adj);
        }
}
