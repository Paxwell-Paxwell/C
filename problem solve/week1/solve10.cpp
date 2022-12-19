
#include <iostream>
using namespace std;

void step1(int N, int *data) {
    for (int i=0;i<N;i++) {
        if (i == 0) {
            if (data[i] == N-1)
                cout << 0 << "\n";
            else if (data[i] == N+1) 
                cout << 1 << "\n";
        }
        else {
            if (data[i] ==data[i-1]+1) 
                cout << 1 << "\n";
            if (data[i] == data[i-1]-1) 
                cout << 0 << "\n";
        }
    }
}

void step2(int N, int *data) {
    int Z[N];
    for (int i=0;i<N;i++) {
        if (i == 0) 
            Z[0] = data[0];
        else {
            if (data[i]-3*Z[i-1] == 1) 
                Z[i] = Z[i-1] + 1;
            else if (2*Z[i-1]-data[i] == 1) 
                Z[i] = Z[i-1] - 1;
            
        }
    }
    step1(N, Z);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, i, j;
    cin >> n >> t;
    int data[n];
    for (i=0;i<n;i++) {
        cin >> data[i];
    }
    int N = n;
    if (t == 1) {
        step1(n, data);
    }
    else if (t == 2) {
        step2(n, data);
    }
    
}