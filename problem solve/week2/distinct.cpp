#include <iostream>
#include <set>
using namespace std;
int sum(int *a_p,int i,int j){
    int total=0;
    for(int k =i;k<=j;k++){
        total+= a_p[k];
    }
    return total;
}
using namespace std;
int main(){
    set<int> price;
    int n;
    cin>>n;
    int p_price[n];
    for(int i=0;i<n;i++) cin>>p_price[i];
    for (int i = 0; i < n; i++)
    {
        for(int j=i;j<n;j++){
            price.insert(sum(p_price,i,j));
        }
    }
    set<int>::iterator it;
    cout<<price.size();
}