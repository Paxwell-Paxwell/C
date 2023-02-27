#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void mer_ge(vector<int> &tmp, vector<int> &v, int l, int m, int r){
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r){
        if (v[i] < v[j]){
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= m){
        tmp[k++] = v[i++];
    }
    while (j <= r){
        tmp[k++] = v[j++];
    }
    for (int i = 0; i < r - l + 1; i++){
        v[l + i] = tmp[i];
    }
}
void MergeSort(vector<int> &v, int l, int r){
    if (l == r) return;
    int m = (l + r) / 2;
    MergeSort(v, l, m);
    MergeSort(v, m + 1, r);
    vector<int> tmp(r - l + 1);
    mer_ge(tmp, v, l, m, r);
}


int main(){
    vector<vector<int> > answer;
    while(true){
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        MergeSort(v, 0, n - 1);
        answer.push_back(v);
    }
    for(auto i: answer){
        for (int j=0; j < i.size(); j++){
            if(i.size() - 1 != j)
                cout << i[j] << " ";
            else
                cout << i[j];

        }
        cout << "\n";
    }
    return 0;
}