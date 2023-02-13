#include <vector>
#include <iostream>
#include <utility>
#include <list>
using namespace std;
typedef struct position{
    int row;
    int col;
}position_t;
int n,k ;
vector< vector<int> > Map;
vector<vector<bool>> seen;
void readInput(){
    cin>>n>>k;
    Map.resize(n , vector<int>(n));
    seen.resize(n, vector<bool>(n, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
        }
    }
}
int BFS(int r, int c, int a, int b) {
    list<pair<int, int>> Queue;
    bool visited[n][n];
    memset(visa, 0, sizeof(visa));
    fill(visited[0], visited[0] + n * n, false);
    Queue.push_back({r, c});
    visited[r][c] = true;
    int cou = 0;
    while (!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop_front();
        int x = p.first;
        int y = p.second;
        if (x == a && y == b) {
            cout << visa[x][y] << "\n";
            return 1;
        }
        if (x + 1 < n && Map[x + 1][y] != '#' && Map[x + 1][y] != 'O' && !visited[x + 1][y]) {
            Queue.push_back({x + 1, y});
            visited[x + 1][y] = true;
        }
        if (x - 1 >= 0 && Map[x - 1][y] != '#' && Map[x - 1][y] != 'O' && !visited[x - 1][y]) {
            Queue.push_back({x - 1, y});
            visited[x - 1][y] = true;
        }
        if (y + 1 < n && Map[x][y + 1] != '#' && Map[x][y + 1] != 'O' && !visited[x][y + 1]) {
            Queue.push_back({x, y + 1});
            visited[x][y + 1] = true;
        }
        if (y - 1 >= 0 && Map[x][y - 1] != '#' && Map[x][y - 1] != 'O' && !visited[x][y - 1]) {
            Queue.push_back({x, y - 1});
            visited[x][y - 1] = true;
        }
    }
    return 0;
}
int main(){
    readInput();
    vector< vector<bool> > seen(n,vector<bool>(n));
    int yes=0;
    position start;
    start.row=0;
    start.col=0;
    if(yes==1){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}

