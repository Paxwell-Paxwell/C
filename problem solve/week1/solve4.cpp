#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    int num[300];
    for(int i =0;i<300;i++){
        num[i]=0;
    }
    int max=0;
    for(int i=0;i<n;i++){
        cin>>a;
        num[a-1]++;
        if (num[a-1]>max){
            max = num[a-1];
        }
    }
    cout << max << "\n";
}
