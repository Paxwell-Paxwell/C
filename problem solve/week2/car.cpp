#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main(){
    stack<int> car;
    int n,price,eff;
    cin>>n;
    int noob_car;
    for (int i = 0; i < n; i++)
    {
        cin>>price>>eff;
        if (car.empty()){
            car.push(eff);
            continue;
        }
        while(!car.empty()&&car.top()<eff)
            car.pop();
        car.push(eff);

    }
    cout<<n-car.size();
}