#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    int base[n];
    bool check[n];
    int start[n];
    for(int i=1;i<=n;i++){
        cin>>base[i-1];
        start[i-1] = i;
        check[i-1] = false;
    }
    
    int c=0,r =0;
    while(true){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(base[j]== start[i])
                { 
                    start[i] = j+1;
                    if(start[i]== i+1){
                    if (check[i]==false){
                        c++;
                    }
                    check[i]=true;
                }
                    break;
                }
                
            }
        }
        r++;
        if(c==n){
            break;
        }
    }
   cout << r << "\n";
}
