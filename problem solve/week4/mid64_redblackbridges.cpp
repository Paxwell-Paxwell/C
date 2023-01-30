#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
vector<vector<int>> red_br,black_br;
int n,m,s,t;
int Bfs(int start ,int end,vector<vector<int>> &adj,int n)
{
    list<int> Q;
    int levels[n];
    fill(levels,levels+n,-1);
    bool seen[n];
    fill(seen,seen+n,false);
    Q.push_back(start);
    seen[start] = true;
    levels[start] = 0;
    while(!Q.empty()) {
            int u = Q.front();
            Q.pop_front();
            if(u == end)
                return levels[u];
            for(int d=0; d<adj[u].size(); d++) {
                int v = adj[u][d];
                if(!seen[v]) {
                    Q.push_back(v);
                    seen[v] = true;
                    levels[v] = levels[u] + 1;
                }
            }
                
        }

    return -1;
}
void readInput(){
    cin>>n>>m>>s>>t;
    s--;t--;
    red_br.resize(n);
    black_br.resize(n);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;u--;v--;
        if(c==1){
            red_br[v].push_back(u);
            red_br[u].push_back(v);
        }
        else if(c==2){
            black_br[v].push_back(u);
            black_br[u].push_back(v);
        }
        else
        {
            red_br[v].push_back(u);
            red_br[u].push_back(v);
            black_br[v].push_back(u);
            black_br[u].push_back(v);
        }
    }
}
int main(){
    readInput();
    int red,black;
    red = Bfs(s,t,red_br,n);
    black = Bfs(s,t,black_br,n);
    int min_b;
    if(red==-1)
        min_b = black;
    else if(black==-1)
        min_b = red;
    else
        min_b = min(red,black);
    cout<<min_b<<'\n';
}
 