#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> banana;
vector<int> max_banana;
int n;
void read_input();
int find_max(int i);
int findBanana(int i,int k);
void read_input()
{
    cin >> n;
    banana.resize(n);
    max_banana.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> banana[i];
    }
}

int find_max(int i)
{
    max_banana[0] = 0;
    max_banana[1] = 0;
    max_banana[2] = banana[2];
    for(int i=3;i<n;i++){
        int tmp = banana[i]+max_banana[i-3];
        if(tmp>max(max_banana[i-1],max_banana[i-2])){
            max_banana[i] = tmp;
        }
        else{
            max_banana[i] = max(max_banana[i-1],max_banana[i-2]);
        }
    }
    // cout<<"max_banana: ";
    // for(int i=0;i<n;i++){
    //     cout << max_banana[i] << " ";
    // }
    cout << "\n";
    return max_banana[i];
}


int main()
{
    read_input();
    int max_b = find_max(n-1);
    cout << max_b << "\n";
    return 0;
}