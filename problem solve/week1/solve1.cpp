#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n;
    int total=0;
    for(int i;i<n;i++){
        cin>>a>>b;
        float r =sqrt(a*a+b*b);
        if (r<=2){
            total+= 5;
        }
        else if (r<=4&&r>2){
             total+= 4;
        }
        else if (r<=6&&r>4){
             total+= 3;
        }
        else if (r<=8&&r>6){
             total+= 2;
        }
        else {
             total+= 1;
        }
    }
    cout << total << "\n";
}


