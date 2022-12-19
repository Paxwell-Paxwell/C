#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,t;
    int count = 1, loop = 1;
    cin >> n >> k >> t;
    loop += k;
    while (loop != 1) {
        loop += k;
        count++;
        if (loop > n) loop %= n;
        if (loop == t) {
            count++;
            break;
            }
    }
    cout << count << "\n";
    return 0;

}
