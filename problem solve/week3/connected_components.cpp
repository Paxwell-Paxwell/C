
#include <vector>
#include <iostream>
using namespace std;

int n,m;

vector<int> *adj;
int *deg;
bool *visited;

void read_input()
{
  scanf("%d %d",&n,&m);
  adj= new vector<int>[n];
  deg= new int[n];
  visited = new bool[n];
  for(int i=0; i<n; i++) {
    deg[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d`   %d",&u,&v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

void init()
{
  fill(visited,visited+n,false);
}

void dfs(int u)
{
  visited[u] = true;
  //cout<<u+1<<" ";
  for(int i=0; i<deg[u]; i++) {
    int v = adj[u][i];
    if(!visited[v]) {
      dfs(v);
    }
  }
}
int main(){
    read_input();
    init();
    int con=0;
    for (int i = 0; i < n; i++)
    {
       if(visited[i]){
            continue;
       }
       dfs(i);
       //cout<<"\n";
       con++;
    }
    cout<<con<<"\n";
    
}