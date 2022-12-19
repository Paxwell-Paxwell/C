#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input
    int n;
    vector<int> ch;
    while (1)
    {
        cin>>n;
        if(n==0)
            break;
        int a[n],min,value=1;
    
        for (int i=0;i<n;i++){
            cin>>a[i];
            if(a[0]==0)
                break;
            if(i==0){
                min = a[0];
                continue;
            }
            if(a[i]= min-1)
                min--;
            else if (){
                
            }
            

        }
    }
    
        
    return 0;
}
