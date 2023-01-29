
#include <vector>
#include <iostream>
using namespace std;

typedef struct position{
    int row;
    int col;
}position_t;
bool right(position_t now,vector< vector<char> > &map){
    if(now.col+1 >=map[now.row].size())
        return false;
    else if (map[now.row][now.col+1]=='#'||map[now.row][now.col+1]=='O')
        return false;
    return true;
} 
bool down(position_t now,vector< vector<char> > &map){
    if(now.row+1 >=map.size())
        return false;
    else if (map[now.row+1][now.col]=='#'||map[now.row+1][now.col]=='O')
        return false;
    return true;
} 
bool left(position_t now,vector< vector<char> > &map){
    if(now.col-1 <0)
        return false;
    else if (map[now.row][now.col-1]=='#'||map[now.row][now.col-1]=='O')
        return false;
    return true;
} 
bool up(position_t now,vector< vector<char> > &map){
    if(now.row-1 <0)
        return false;
    else if (map[now.row-1][now.col]=='#'||map[now.row-1][now.col]=='O')
        return false;
    return true;
} 
void dfs(position_t now,position_t end,vector< vector<char> > &map, vector< vector<bool> > &seen,int* yes,int &key){
    seen[now.row][now.col] = true;
    if(now.row==end.row&&now.col==end.col)
        *yes=1;
    position_t next;
    if(right(now,map)&&!seen[now.row][now.col+1]){
        next.row =now.row;
        next.col=now.col+1; 
        dfs(next,end,map,seen,yes,key);
    }
    if(down(now,map)&&!seen[now.row+1][now.col]){
        next.row =now.row+1;
        next.col=now.col; 
        dfs(next,end,map,seen,yes,key);
    }
    if(left(now,map)&&!seen[now.row][now.col-1]){
        next.row =now.row;
        next.col=now.col-1; 
        dfs(next,end,map,seen,yes,key);
    }
    if(up(now,map)&&!seen[now.row-1][now.col]){
        next.row =now.row-1;
        next.col=now.col;
        dfs(next,end,map,seen,yes,key);
    }
}
  
int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<bool> > seen(n,vector<bool>(n));
    vector<position> box;
    vector< vector<char> > map(n, vector<char>(n));
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int r,c,a,b;
        cin>>r>>c>>a>>b;r--;c--;a--;b--;
        int key=0,yes=0;
        position_t start={r,c},end={a,b};
        dfs(start,end,map,seen,&yes,key);
        ans.push_back(yes);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i]==1)
            cout<<"yes"<<"\n";
        else
            cout<<"no"<<"\n";
    }
    
}