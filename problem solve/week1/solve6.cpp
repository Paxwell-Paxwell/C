#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,id;
    int s;
    cin>>n>>k;
    s=n;
    long long int run[n],min=999999999999;
    for(int i=0;i<n;i++){
        cin>>run[i];
        if (min>=run[i]){
            min = run[i];
            id = i;
        }
    }

    for(int i=0;i<n;i++){
        if(i==id)
            continue;
        if(min*k<=run[i]*(k-1)){
            s--;
      } 
    }
    cout<<s<<"\n";
}
