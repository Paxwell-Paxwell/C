#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef struct bridge{
    int start;
    int end;
}bridge_t;
bool check(double point,bridge_t br){
    if(point>br.start&&point<br.end)
        return true;
    return false;
}
int main(){
    vector<bridge_t> all_bridge;
    int l,n;
    cin>>l>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        bridge new_br;
        cin>>a>>b;
        new_br.start = a;
        new_br.end =b;
        all_bridge.push_back(new_br);
    }
    int max=0,tmp=0;
    for(double i=0;i<l;i+=0.1)
    {
        tmp=0;
        for (int j = 0; j < n; j++)
        {
            if(check(i,all_bridge[j]))
                tmp++;
        }
        if (tmp>max)
            max=tmp;
    }
    cout<<max;
}