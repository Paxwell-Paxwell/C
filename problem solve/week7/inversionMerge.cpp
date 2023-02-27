#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int  mer_ge(vector<long long int> &tmp, vector<long long int> &v, long long int l, long long int m, long long int r){
    long long int i = l, j = m+1, k = 0;
    long long int inv_count = 0;
    while (i <= m && j <= r){
        if (v[i] < v[j]){
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
            inv_count += m-i+1;
        }
    }
    while (i <= m){
        tmp[k++] = v[i++];
    }
    while (j <= r){
        tmp[k++] = v[j++];
    }
    for (long long int i = 0; i < r - l + 1; i++){
        v[l + i] = tmp[i];
    }
    return inv_count;
}
long long int MergeSort_inversion(vector<long long int> &v, long long int l, long long int r){
    long long int inv_count = 0;
    if(l==r) return inv_count;
    long long int m = (l + r) / 2;
    inv_count += MergeSort_inversion(v, l, m);
    inv_count += MergeSort_inversion(v, m + 1, r);
    vector<long long int> tmp(r - l + 1);
    inv_count += mer_ge(tmp, v, l, m, r);
    return inv_count;
}


int main(){
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << MergeSort_inversion(v, 0, n - 1);

    
    return 0;

}