#include <vector>
#include <iostream>
#include <list>
using namespace std;

struct question {
    int r, c;
    int a, b;
};

int n, q;
vector<string> Map;
vector<question> start_end;

void get_input() {
    cin >> n >> q;
    Map.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> Map[i];
    }
    start_end.resize(q);
    for (int i=0;i<q;i++) {
        cin >> start_end[i].r >> start_end[i].c >> start_end[i].a >> start_end[i].b; start_end[i].r--; start_end[i].c--; start_end[i].a--; start_end[i].b--;
    }
}

//this can't pass door anymore
int BFSs(int r, int c, int a, int b) {
    list<pair<int, int>> Queue;
    bool visited[n][n];
    fill(visited[0], visited[0] + n * n, false);
    Queue.push_back({r, c});
    visited[r][c] = true;
    while (!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop_front();
        int x = p.first;
        int y = p.second;
        if (x == a && y == b) {
            cout << "yes" << "\n";
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

//this can still go if encounter a door
void BFS(int r, int c, int a, int b) {
    list<pair<int, int>> Queue;
    bool visited[n][n]; 
    fill(visited[0], visited[0] + n * n, false);
    Queue.push_back({r, c});
    visited[r][c] = true;
    while (!Queue.empty()) {
        pair<int, int> p = Queue.front();
        Queue.pop_front();
        int x = p.first;
        int y = p.second;
        if (x == a && y == b) {
            cout << "yes" << "\n";
            return;
        }
        if (x + 1 < n && Map[x + 1][y] != '#' && !visited[x + 1][y]) {
            if (Map[x + 1][y] == 'O') {
                if (BFSs(x + 1, y, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x + 1, y});
                visited[x + 1][y] = true;
            }
        }
        if (x - 1 >= 0 && Map[x - 1][y] != '#' && !visited[x - 1][y]) {
            if (Map[x - 1][y] == 'O') {
                if (BFSs(x - 1, y, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x - 1, y});
                visited[x - 1][y] = true;
            }
        }
        if (y + 1 < n && Map[x][y + 1] != '#' && !visited[x][y + 1]) {
            if (Map[x][y + 1] == 'O') {
                if (BFSs(x, y + 1, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x, y + 1});
                visited[x][y + 1] = true;
            }
        }
        if (y - 1 >= 0 && Map[x][y - 1] != '#' && !visited[x][y - 1]) {
            if (Map[x][y - 1] == 'O') {
                if (BFSs(x, y - 1, a, b)) {
                    return;
                }
            } else {
                Queue.push_back({x, y - 1});
                visited[x][y - 1] = true;
            }
        }
    }
    cout << "no" << "\n";
}

void Answer() {
    for (auto ques : start_end) {
        BFS(ques.r, ques.c, ques.a, ques.b);
    }
}

int main()
{
    get_input();
    Answer();
    return 0;
}