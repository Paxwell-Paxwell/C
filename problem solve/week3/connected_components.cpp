
#include <vector>
#include <iostream>
using namespace std;

#define MAX_N  100000

int n,m;

vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++) {
    deg[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d %d",&u,&v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool visited[MAX_N];

void init()
{
  fill(visited,visited+MAX_N,false);
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
    for (int i = 0; i < 100000; i++)
    {
       if(visited[i]||deg[i]==0){
            continue;
       }
       dfs(i);
       //cout<<"\n";
       con++;
    }
    cout<<con<<"\n";
    
}