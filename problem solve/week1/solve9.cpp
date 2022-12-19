
#include <iostream>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int  x = 0, y = 0;
    string walk = "";
    cin >> walk;
    for (int i=0;i<100;i++) {
        if (walk[i] == '\0') break;
        else if (walk[i] == 'N') y += 1;
        else if (walk[i] == 'S') y -= 1;
        else if (walk[i] == 'E') x += 1;
        else if (walk[i] == 'W') x -= 1;
        else if (walk[i] == 'Z') {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y << "\n";
}