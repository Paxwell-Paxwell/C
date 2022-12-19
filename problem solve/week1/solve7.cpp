#include <iostream>
using namespace std;


int main() {
    int n, count = 0, tmp, ch = 0;
    int num[301];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int j = 0; j < n; j++) {
        tmp = num[j];
        ch=j;
        while (true) {
            if (ch == n-1) {
                break;
            }
            if (num[ch+1] > tmp) {
                count++;
            }
            ch++;
        }
    }
    cout << count << "\n";
}