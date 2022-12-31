
#include <vector>
#include <iostream>
using namespace std;

typedef struct position{
    int row;
    int col;
}position_t;
void reset_seen( vector< vector<bool> > &seen){
    for(int i=0;i<seen.size();i++){
        for(int j=0;j<seen[i].size();j++){
            seen[i][j]=false;
        }
    }
}
bool right(position_t now,vector< vector<char> > &map){
    if(now.col+1 >=map[now.row].size())
        return false;
    else if (map[now.row][now.col+1]=='#')
        return false;
    return true;
} 
bool down(position_t now,vector< vector<char> > &map){
    if(now.row+1 >=map.size())
        return false;
    else if (map[now.row+1][now.col]=='#')
        return false;
    return true;
} 
bool left(position_t now,vector< vector<char> > &map){
    if(now.col-1 <0)
        return false;
    else if (map[now.row][now.col-1]=='#')
        return false;
    return true;
} 
bool up(position_t now,vector< vector<char> > &map){
    if(now.row-1 <0)
        return false;
    else if (map[now.row-1][now.col]=='#')
        return false;
    return true;
} 
void dfs(position_t now,vector< vector<char> > &map, vector< vector<bool> > &seen,vector< vector<int> > &score){
    seen[now.row][now.col] = true;
    score[now.row][now.col]++;
    position_t next;
    if(right(now,map)&&!seen[now.row][now.col+1]){
        next.row =now.row;
        next.col=now.col+1; 
        dfs(next,map,seen,score);
    }
    if(down(now,map)&&!seen[now.row+1][now.col]){
        next.row =now.row+1;
        next.col=now.col; 
        dfs(next,map,seen,score);
    }
    if(left(now,map)&&!seen[now.row][now.col-1]){
        next.row =now.row;
        next.col=now.col-1; 
        dfs(next,map,seen,score);
    }
    if(up(now,map)&&!seen[now.row-1][now.col]){
        next.row =now.row-1;
        next.col=now.col;
        dfs(next,map,seen,score);
    }
}
  
int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<bool> > seen(n,vector<bool>(m));
    vector< vector<int> >  score(n,vector<int>(m));
    vector<position_t> asset[2];
    vector< vector<char> > map(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j]=='*'){
                position_t forest;
                forest.row=i;
                forest.col=j;
                asset[0].push_back(forest);
            }
            else if(map[i][j]=='$'){
                position_t mineral;
                mineral.row=i;
                mineral.col=j;
                asset[1].push_back(mineral);
            }
        }
    }
    for(int i=0;i<2;i++){
        for (auto it = asset[i].begin(); it != asset[i].end(); it++)
        {
            position_t start= *it;
            if(!seen[start.row][start.col])
                dfs(start,map,seen,score);
            
        }
        reset_seen(seen);
    }
    int level_2=0,level_1=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        if(score[i][j]==2)
            level_2++;
        else if(score[i][j]==1)
            level_1++;
    }
    }
    cout <<level_2<<" "<<level_1<< "\n";
}