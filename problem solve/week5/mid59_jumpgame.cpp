#include <vector>
#include <iostream>
using namespace std;
typedef struct position{
    int row;
    int col;
}position_t;
int n,k ;
vector< vector<int> > map;
vector<vector<bool>> seen;
void readInput(){
    cin>>n>>k;
    map.resize(n , vector<int>(n));
    seen.resize(n, vector<bool>(n, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
}
void jump(position now,int *yes,int from){
    seen[now.row][now.col] = true;
    //cout<<"now.row:"<<now.row<<" now.col:"<<now.col<<endl;
    if(now.row==n-1&&now.col==n-1){
        *yes=1;
        return;
    }
    if(now.col+1<n&&map[now.row][now.col+1]-from<=k&&!seen[now.row][now.col+1]){
        position next;
        next.row=now.row;
        next.col=now.col+1;
        jump(next,yes,map[now.row][now.col+1]);
    }
    if(now.row+1<n&&map[now.row+1][now.col]-from<=k&&!seen[now.row+1][now.col]){
        position next;
        next.row=now.row+1;
        next.col=now.col;
        jump(next,yes,map[now.row+1][now.col]);
    }
    if(now.col-1>=0&&map[now.row][now.col-1]-from<=k&&!seen[now.row][now.col-1]){
        position next;
        next.row=now.row;
        next.col=now.col-1;
        jump(next,yes,map[now.row][now.col-1]);
    }
    if(now.row-1>=0&&map[now.row-1][now.col]-from<=k&&!seen[now.row-1][now.col]){
        position next;
        next.row=now.row-1;
        next.col=now.col;
        jump(next,yes,map[now.row-1][now.col]);
    }
}
int main(){
    readInput();
    vector< vector<bool> > seen(n,vector<bool>(n));
    int yes=0;
    position start;
    start.row=0;
    start.col=0;
    jump(start,&yes,map[0][0]);
    if(yes==1){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}

