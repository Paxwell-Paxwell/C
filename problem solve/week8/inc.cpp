#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n =0;
vector<int> num;
vector<vector<int>> answer;
void read_input(){
    cin >> n;
    num.resize(n);
    answer.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for(int i=0;i<n;i++){
        answer[i].push_back(num[i]);
    }
}
vector<int> findmax(int i){
    vector<int> tmp;
    int max_size = 0;
    for(int j=0;j<i;j++){
        if(num[i]>num[j]){
            if(answer[j].size()>max_size){
                max_size = answer[j].size();
                tmp = answer[j];
            }
        }
    }
    tmp.push_back(num[i]);
    return tmp;
}
void solve(){
    for(int i=1;i<n;i++){
        answer[i] = findmax(i);
    }
}
int main(){
    read_input();
    solve();
    int max_size = 0;
    vector<int> tmp;
    for(int i=0;i<n;i++){
        if(answer[i].size()>max_size){
            max_size = answer[i].size();
            tmp = answer[i];
        }
    }
    cout << max_size << "\n";
    for(int i=0;i<tmp.size();i++){
        cout << tmp[i] << " ";
    }

}