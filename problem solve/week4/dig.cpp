#include <vector>
#include <iostream>
#include <list>
#include <utility>
using namespace std;

struct question {
    int r, c;
    int a, b;
};

int n,m,q,c_dig=0;
vector<string> Map;
question start_end;

void get_input() {
    cin >> n >> m;
    cin>>start_end.r>>start_end.c>>start_end.a>>start_end.b;start_end.r--;start_end.c--;start_end.a--;start_end.b--;
    Map.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> Map[i];
    }
}
bool a_dig(int row,int col){
    if(Map[row][col]=='.')
       return false;
    if(Map[row][col]=='#')
        return false;
    if(Map[row-1][col]=='.'&&Map[row+1][col]=='.'){
        return true;
    }
    if(Map[row][col-1]=='.'&&Map[row][col+1]=='.'){
        return true;
    }
   return false;
}
int BFS(int r, int c, int a, int b) {
    list<pair<int, int>> Queue;
    vector<vector<int>> levels(n,vector<int>(m,-1));
    bool visited[n][m];
    fill(visited[0], visited[0] + n * m, false);
    Queue.push_back({r, c});
    levels[r][c] = 0;
    visited[r][c] = true;
    while (!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop_front();
        int x = p.first;
        int y = p.second;
        if (x == a && y == b) {
            return levels[x][y];
        }
        if (x + 1 < n && Map[x + 1][y] != '#' &&Map[x + 1][y] != '*' && !visited[x + 1][y]) {
            Queue.push_back({x + 1, y});
            levels[x + 1][y] = levels[x][y] + 1;
            visited[x + 1][y] = true;

        }
        if (x - 1 >= 0 && Map[x - 1][y] != '#' &&Map[x-1][y] != '*' && !visited[x - 1][y]) {
            Queue.push_back({x - 1, y});
            levels[x - 1][y] = levels[x][y] + 1;
            visited[x - 1][y] = true;
        }
        if (y + 1 < n && Map[x][y + 1] != '#' &&Map[x][y+1] != '*' && !visited[x][y + 1]) {
            Queue.push_back({x, y + 1});
            levels[x][y + 1] = levels[x][y] + 1;
            visited[x][y + 1] = true;
        }
        if (y - 1 >= 0 && Map[x][y - 1] != '#' && Map[x][y-1] != '*' && !visited[x][y - 1]) {
            Queue.push_back({x, y - 1});
            levels[x][y - 1] = levels[x][y] + 1;
            visited[x][y - 1] = true;
        }
    
}
    return 1000000;
}

int main()
{
    get_input();
    vector<pair<int,int>> dig;
    dig.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a_dig(i,j)){
                dig.push_back({i,j});
            }
        }
    }
    int min_g=1000000;
    int tmp = BFS(start_end.r,start_end.c,start_end.a,start_end.b);
    if(tmp<min_g)
        min_g=tmp;
    for(int i=0;i<dig.size();i++){
        Map[dig[i].first][dig[i].second]='.';
        tmp = BFS(start_end.r,start_end.c,start_end.a,start_end.b);
        //cout<<tmp<<"\n";
        if(tmp<min_g)
            min_g=tmp;
        Map[dig[i].first][dig[i].second]='*';
    }
    if(min_g==1000000)
        cout<<"-1"<<"\n";
    else
        cout<<min_g<<"\n";
}   