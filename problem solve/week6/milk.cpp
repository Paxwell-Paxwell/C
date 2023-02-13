#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
const int MAXN = 100001;
int parent[MAXN];
int psize[MAXN];
vector<string> ans;
int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}
void union_sets(int u, int v)
{
    u = find(u);
    v = find(v);
    if (psize[u] < psize[v])
    {
        parent[u] = v;
        psize[v] += psize[u];
    }
    else
    {
        parent[v] = u;
        psize[u] += psize[v];
    }
}
void readInputAnswer(){
    cin >> n >> m;
    char q;
    int a,b;
    for(int i = 0; i < n; i++){
        parent[i] = i;
        psize[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin>>q>>a>>b;a--;b--;
        if( q== 'c'){
            union_sets(a,b);
        }
        else{
            if(find(a) == find(b)){
                ans.push_back("yes");
            }
            else{
                ans.push_back("no");
            }
        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    readInputAnswer();
    for(auto i:ans){
        cout<<i<<"\n";
    }
}