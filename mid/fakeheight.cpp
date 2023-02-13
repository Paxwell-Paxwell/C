#include <vector>
#include <iostream>
#include <list>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n,m ,a,b,r,c;
int max_i= 0;
vector< vector<int> > Map;
vector<unordered_set<int>> con;
void readInput(){
    cin>>n>>m>>a>>b>>r>>c;a--;b--;r--;c--;
    Map.resize(n , vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            max_i = max(max_i , Map[i][j]);
        }
    }


}
void ch_con(){
    con.resize(max_i);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+1<n && Map[i][j] != Map[i+1][j]){
                con[Map[i][j]-1].insert(Map[i+1][j]-1);
                con[Map[i+1][j]-1].insert(Map[i][j]-1);
            }
            if(j+1<n && Map[i][j] != Map[i][j+1]){
                con[Map[i][j]-1].insert(Map[i][j+1]-1);
                con[Map[i][j+1]-1].insert(Map[i][j]-1);
            }
            if(i-1>=0 && Map[i][j] != Map[i-1][j]){
                con[Map[i][j]-1].insert(Map[i-1][j]-1);
                con[Map[i-1][j]-1].insert(Map[i][j]-1);
            }
            if(j-1>=0 && Map[i][j] != Map[i][j-1]){
                con[Map[i][j]-1].insert(Map[i][j-1]-1);
                con[Map[i][j-1]-1].insert(Map[i][j]-1);
            }

        }
    }
}
int bfs_magic(int start,int end){
    list<int> Q;
    int levels[max_i];
    //bool seen[max_i];
    fill(levels,levels+max_i,-1);
    //fill(seen,seen+max_i,false);
    Q.push_back(start);
    //seen[start] = true;
    levels[start] = 0;
    if(start == end){
        return 0;
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(auto v: con[u]){
            if(levels[v]==-1) {
                    Q.push_back(v);
                    levels[v] = levels[u] + 1;
                    //seen[v] = true;
                    if(v == end){
                        return levels[v];
                    }
                }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<"level"<<levels[i]<<" ";
    // }
    return levels[end]; 
 }
int main(){
    readInput();
    ch_con();
    //cout<<max_i<<"\n";
    // for (int i = 0; i < con.size(); i++) {
    //     cout << "Set " << i+1 << ": ";
    //     for (auto it = con[i].begin(); it != con[i].end(); it++) {
    //         cout << *it +1<< " ";
    //     }
    //     cout << endl;
    // }
    //cout<<a<<" "<<b<<" "<<r<<" "<<c<<"\n";
    //cout<<Map[a][b]<<" "<<Map[r][c]<<"\n";
    int start = Map[a][b]-1;
    int end = Map[r][c]-1;
    cout<<bfs_magic(start,end);
    return 0;
}