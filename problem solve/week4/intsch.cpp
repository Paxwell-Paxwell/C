#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct intsch
{
    int start,end;
    int timee;
};
bool compare_wf(intsch &a, intsch &b) {
  return a.timee < b.timee;
}
bool compare_ws(intsch &a, intsch &b) {
  return a.end < b.end;
}
bool check_sc(vector<int> &schedule,intsch &work){
    bool check = true;
    for(int i = work.start-1 ;i<work.end-1;i++){
        if(schedule[i]){
            check =false;
            break;
        }
    }
    if(check){
        for(int i = work.start-1 ;i<work.end-1;i++){
            schedule[i] =true;
    }
    }
    return check;
}
int main(){
    list<intsch> all_work;
    int n;
    cin>>n;
    int s,e;
    int max=0;
    for (int i = 0; i < n; i++)
    {
        intsch n_work;
        cin>>s>>e;
        n_work.start=s;
        n_work.end=e;
        n_work.timee =e-s;
        if(e>max)
            max=e;
        all_work.push_back(n_work);
    }
    all_work.sort(compare_wf);
    all_work.sort(compare_ws);
    vector<int> schedule(max);
    int c=0;
    for (auto it = all_work.begin(); it != all_work.end(); it++)
    {
        if(check_sc(schedule,*it)){
            c++;
        }
    }
    cout<<c;
    
}
