
#include <vector>
#include <iostream>
using namespace std;

typedef struct position{
    int row;
    int col;
}position_t;
bool right(position_t now,vector< vector<char> > &map){
    if(now.col+2 >=map[now.row].size())
        return false;
    else if (map[now.row][now.col+2]=='#'||map[now.row+1][now.col+2]=='#')
        return false;
    return true;
} 
bool down(position_t now,vector< vector<char> > &map){
    if(now.row+2 >=map.size())
        return false;
    else if (map[now.row+2][now.col]=='#'||map[now.row+2][now.col+1]=='#')
        return false;
    return true;
} 
bool left(position_t now,vector< vector<char> > &map){
    if(now.col-1 <0)
        return false;
    else if (map[now.row][now.col-1]=='#'||map[now.row+1][now.col-1]=='#')
        return false;
    return true;
} 
bool up(position_t now,vector< vector<char> > &map){
    if(now.row-1 <0)
        return false;
    else if (map[now.row-1][now.col]=='#'||map[now.row-1][now.col+1]=='#')
        return false;
    return true;
} 
void dfs(position_t now,vector< vector<char> > &map, vector< vector<bool> > &seen,int* yes){
    seen[now.row][now.col] = true;
    if(now.row==map.size()-2)
        *yes=1;
    position_t next;
    if(right(now,map)&&!seen[now.row][now.col+1]){
        next.row =now.row;
        next.col=now.col+1; 
        dfs(next,map,seen,yes);
    }
    if(down(now,map)&&!seen[now.row+1][now.col]){
        next.row =now.row+1;
        next.col=now.col; 
        dfs(next,map,seen,yes);
    }
    if(left(now,map)&&!seen[now.row][now.col-1]){
        next.row =now.row;
        next.col=now.col-1; 
        dfs(next,map,seen,yes);
    }
    if(up(now,map)&&!seen[now.row-1][now.col]){
        next.row =now.row-1;
        next.col=now.col;
        dfs(next,map,seen,yes);
    }
}
  
int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<bool> > seen(n,vector<bool>(m));
    vector<position> box;
    vector< vector<char> > map(n, vector<char>(m));
    int yes=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int j=0;j<m-1;j++){
        position new_box;
        if(map[0][j]=='.'&&map[0][j+1]=='.'&&map[1][j]=='.'&&map[1][j+1]=='.'){
            new_box.row=0;
            new_box.col=j;
            box.push_back(new_box);
        }
   }
   for (int i = 0; i < box.size(); i++)
   {
        dfs(box[i],map,seen,&yes);
        if(yes) break;
   }
    if (yes)
        cout<<"yes"<<"\n";
    else
        cout<<"no"<<"\n";
   
}