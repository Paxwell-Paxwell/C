#include <vector>
#include <iostream>
#include <cmath>
#include <list>

using namespace std;
void topo_order(int n,vector<int> *adj,int *indeg,int *outdeg,vector<int> &output,int *topo)
{
  list<int> s;

  int ch =1;
  for(int u=0; u<n; u++)
    if(indeg[u] == 0){
      ch=0;
      s.push_back(u);
    }
  if(ch){
    *topo = 0;
    return;
  }
  for(int i=0; i<n; i++) {
    int u = s.front();
    s.pop_front();
    output.push_back(u);

    for(int d=0; d < outdeg[u]; d++) {
      int v = adj[u][d];
      if(indeg[v]==0){
        *topo = 0;
        return;
      }
      indeg[v]--;
      if(indeg[v] == 0) {
        s.push_back(v);
      } 
    }
  }
}
int main(){
    int n,m;
    cin>>n>>m;
    int indeg[n];
    int outdeg[n];
    vector<int> adj[n];
    fill(indeg,indeg+n,0);
    fill(outdeg,outdeg+n,0);
    vector<int> output;
    int topo = 1;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;u--;v--;
        indeg[v]++;
        outdeg[u]++;
        adj[u].push_back(v);
    }
    topo_order(n,adj,indeg,outdeg,output,&topo);
    if(topo){
        for(int i=0;i<output.size();i++){
            cout<<output[i]+1<<"\n";
        }
    }
    else
        cout<<"no"<<"\n";

}