#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool comparefirst( pair<int,int> &a,  pair<int,int> &b){
    return a.first<b.first;
}
pair<int,int> findMax(vector<pair<int,int> > &range, int endPoint){
    pair<int,int> max_range;
    int distmax=-1000000000;
    for(int i=0;i<range.size();i++){
        if(range[i].first>endPoint) break;
        if(distmax<=range[i].second){
            distmax = range[i].second;
            max_range = range[i];
        }
    }
    return max_range;
}
vector<pair<int,int>> minimal_coverage(int m, vector<pair<int,int>> &range){
    vector<pair<int,int>> ans;
    int endPoint=0;
    pair<int,int> tmp;
    while (endPoint<m)
    {
        pair<int,int> max_range = findMax(range,endPoint);
        if (ans.empty()){
            endPoint = max_range.second;
            ans.push_back(max_range);
        }
        else {
            if(ans[ans.size()-1].first==max_range.first && ans[ans.size()-1].second==max_range.second) {
                ans.clear();
                break;}
            endPoint = max_range.second;
            ans.push_back(max_range);
        }

    }
    return ans;
}
void print_minimal(vector<pair<int,int>> &ans){
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}
int main(){
    int k;
    cin>>k;
    vector<vector<pair<int,int> > > all_ans;
    for (int i = 0; i < k; i++)
    {
        cout<<"\n";
        int m,l,r;
        cin>>m;
        vector<pair<int,int> > range,ans;
        while(1){
            cin>>l>>r;
            if(l==0 && r==0) break;
            range.push_back(make_pair(l,r));
        }
        sort(range.begin(),range.end(),comparefirst);
        all_ans.push_back(minimal_coverage(m,range));
    }
    for (int i = 0; i < k; i++)
    {
        print_minimal(all_ans[i]);
        cout<<"\n";
    }
    
    
}