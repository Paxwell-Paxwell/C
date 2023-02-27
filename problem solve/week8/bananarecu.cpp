#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 100010;
int banana[MAX_N];
int max_total[MAX_N] ={0};

int n;
int max_select(int s);


int max_banana(int s) //eat at s
{
  int m =0, tmp;
  for (int i=0; i<3; i++)
  {
    if (max_total[s-i] ==0)
      tmp = max_select(s-i);
    else tmp = max_total[s-i];
    if (tmp >m) m = tmp;
  }
  return m;
}
int max_select(int s)
{
  if (s < 2) return 0;
  if (s==2) return banana[2];
  int maxx = max_banana(s-3);
  max_total[s] = banana[s] + maxx;
  return max_total[s];
}

int main()
{
  cin >> n;
  for (int i=0; i<n; i++)
  {
    cin >> banana[i];
  }
  
  int res = max_banana(n);
  cout<<"max_total: "<<"\n";
  for(int i=0;i<n;i++){
    cout << max_total[i] << " ";
  }
  cout << res ;
}