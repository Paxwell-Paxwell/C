
#include <vector>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

typedef struct position{
    int x;
    int y;
}position_t;
int hash_key(position position){
    return position.x*100+position.y;
}
bool check_r(position s_pos,position e_pos,int r)
{
    int diff = pow(s_pos.x-e_pos.x,2)+pow(s_pos.y-e_pos.y,2);
    if(diff <= (r*r))
        return true;
    else 
        return false;
    
}
void find_levels(position_t s_pos, vector<position_t> *adj,int *levels)
{
  list<position_t> next_level;
  int key = hash_key(s_pos);
  next_level.push_back(s_pos);
  levels[key] = 0;
  
  while(! next_level.empty()) {
    list<position_t> current_level = next_level;
    next_level.clear();

    for(auto i = current_level.begin();
        i != current_level.end(); i++) {
        int u = hash_key(*i);
      
      for(auto j = adj[u].begin();
          j != adj[u].end(); j++) {
        int v = hash_key(*j);

        if(levels[v] == -1) {
          levels[v] = levels[u] + 1;
          next_level.push_back(*j);
        }
      }
    }
  }
}
int main(){
    vector<int> key;
    vector<position_t>  adj[10101];
    int levels[10101];
    fill(levels,levels+10101,-1);
    int n,r;
    cin>>n>>r;
    vector<position_t> all_pos;
    position_t start;
    start.x=0;
    start.y=0;
    all_pos.push_back(start); 
    for (int i = 0; i < n; i++)
    {
        position_t new_pos;
        int x,y;
        cin>>x>>y;
        new_pos.x=x; new_pos.y=y;
        for (int j = 0; j < all_pos.size(); j++)
        {
            if(check_r(new_pos,all_pos[j],r)){
                adj[hash_key(all_pos[j])].push_back(new_pos);
                adj[hash_key(new_pos)].push_back(all_pos[j]);
            }
        }
        all_pos.push_back(new_pos);
    }
    position_t end;
    end.x=100;
    end.y=100;
    all_pos.push_back(end);
    for (int j = 0; j < all_pos.size(); j++)
        {
            if(check_r(end,all_pos[j],r)){
                adj[hash_key(all_pos[j])].push_back(end);
                adj[hash_key(end)].push_back(all_pos[j]);
            }
        }
    find_levels(start,adj,levels);
    cout<<levels[10100]<<"\n";\
}
