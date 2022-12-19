#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    int total=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if (a>=0){
            total += a;
        }
    }
    cout << total << "\n";
}


