#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int base[n];
    int check[n];
    int max = 0 ,ch;
    for(int i=1;i<=n;i++){
        cin>>base[i-1];
        check[i-1]=0;
    }
    for(int i=1;i<=n;i++){
        int count =1;
        ch = base[i-1];
        if(check[ch-1]==1)
            continue;
        while(true){
            if(ch==i)
                break;
            check[ch-1]=1;
            ch = base[ch-1];
            count++;
        }

        if(count>max)
            max =count;
    }
    cout<<max<<"\n";
}
