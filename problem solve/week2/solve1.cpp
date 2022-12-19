#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input
    int n;
    vector<int> ch,bl;
    while (cin>>n)
    {
        if(n==0)
            break;
        int a[n],min,value;
        int out = 1;
        int index = 0;
        while(out){
            value =1;
            for (int i=0;i<n;i++){
                cin>>a[i];
                if(a[0]==0){
                    bl.push_back(index);
                    index = 0;
                    out = 0;
                    break;
                }
                if(i==0){
                    min = a[0];
                    continue;
                }
                if(a[i]==min-1)
                    min--;
                else if (a[i]>min)
                    continue;
                else{
                    value =0;
                }
            }
            if (a[0] != 0){
                index++;
                ch.push_back(value);
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