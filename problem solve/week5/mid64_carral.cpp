#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
struct contract
{
    int ci,pi,wi;
};
vector<contract> contracts;
vector<int> parcel;
void readInput(){
    cin>>n>>m;
    contracts.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>contracts[i].ci>>contracts[i].pi>>contracts[i].wi;
    }
    parcel.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin>>parcel[i];
    }
}

int price(contract car){
    
    int weight =0,count=1;
    for (int i = 0; i < m; i++)
    {
        weight+=parcel[i];
        if(weight<=car.wi){
            continue;
        }
        else{
            count++;
            weight=parcel[i];
        }
            
    }
    return count*car.pi+car.ci;


}
void solve(){
    int minPrice=INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int max = *max_element(parcel.begin(),parcel.end());
        if(contracts[i].wi<max){
            continue;
        }
        minPrice=min(minPrice,price(contracts[i]));
    }
    cout<<minPrice;
}
int main(){
    readInput();
    solve();
    return 0;
}