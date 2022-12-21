#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int check(int *data,int n){
    stack<int> rail;
    rail.push(0);
    int i=1,k=0;
    while(1){
        //cout<<i<<" "<<k<<"\n";
        if(i<=n&&rail.top()!=data[k]){
            rail.push(i); i++;
            continue;
        }
        if(rail.top()==data[k]){
            rail.pop();
            k++;

        }
        if(k>=n)
            return 1;
        if(i>n && rail.top()!=data[k])
            return 0;

    }
    return 1;
}

int main() {
    // Read input
    int n;
    vector<int> ch,bl;
    while (cin>>n)
    {
        if(n==0)
            break;
        int value,k=0;
        while(1){
            int a[n];
            for(int i=0;i<n;i++){
                cin>>a[i];
                if (a[0]==0)
                    break;
            }
            if(a[0]==0) {
                bl.push_back(k);
                break;
            }
            
            if(a[0]!=0) {

                value  = check(a,n) ;
                ch.push_back(value);
                k++;
            }
        }
        
        

    }
    vector<int>::iterator it,ib;

    ib = bl.begin();
    int k  = 0,i=0;
    for (it = ch.begin();it != ch.end();it++)
    {
        if (*it) cout << "Yes" << "\n";
        else cout << "No" << "\n";
        i++;
        if (*(ib+k)==i){
            cout<<"\n";
            k++;
        }
    }
    return 0;
}