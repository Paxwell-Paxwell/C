
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int n,m,k,start;
vector<int> work;
vector<vector<int>> adj;
int seen[100001];
int bipar(int start)
{
  list<int> Q;
  int levels[n];
  fill(levels, levels + n, -1);
  Q.push_back(start);
  levels[start] = 0;
  seen[start] = true;
  while(! Q.empty()) {
   
    int u = Q.front();
    Q.pop_front();
    if(work[u]>k){
        continue;
    }

    for(int d=0; d<adj[u].size(); d++) {
        int v = adj[u][d];

        if(work[v]>=k){
            continue;
        }
        if(levels[v]==levels[u]){
            //cout<<"v: "<<v+1<<" u: "<<u+1<<" levels[v]: "<<levels[v]<<" levels[u]: "<<levels[u]<<endl;
            return 0;
        }
        if(!seen[v]) {
	        Q.push_back(v);
	        seen[v] = true;
	        levels[v] = levels[u] + 1;
        }
        } 
    }
  
  return 1;
}
void readInput(){
    cin>>n>>m>>k;
    adj.resize(n);
    work.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;a--;b--;
        if(i==0)start=a;

        adj[a].push_back(b);
        adj[b].push_back(a);
        work[a]++;
        work[b]++;
    }
}
int main(){  
    readInput();
    for(int i=0;i<n;i++){
        if(seen[i]==1){
            continue;
        }
        if(work[i]>=k){
            continue;
        }
        //cout<<work[i];
        //cout<<"i: "<<i+1<<endl;
        if(bipar(i)==0){
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
}
