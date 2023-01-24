#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct work
{
    int d_line;
    int work_time;
};
bool compare_w(work &a, work &b) {
  return a.d_line < b.d_line;
}
int main(){
    int n;
    cin>>n;
    int d,j;
    vector<work> all_work;
    for(int i=0;i<n;i++){
        cin>>d>>j;
        work n_work;
        n_work.d_line=d;
        n_work.work_time=j;
        all_work.push_back(n_work);
    }
    sort(all_work.begin(),all_work.end(),compare_w);
    
    int max=0,t=0,dif;
    for (int i = 0; i < n; i++)
    {
        t += all_work[i].work_time;
        dif = t-all_work[i].d_line;
        if(dif > 10 &&max<dif-10){
             dif =dif-10;
             max =dif;
        }
    }
    cout<<max*1000;
    
}
