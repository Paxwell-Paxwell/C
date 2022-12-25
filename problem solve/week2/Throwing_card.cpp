#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void find_sequence(int n,vector< vector<int> > &discard,vector<int> &lastcard) {
  queue<int> queue;
  for (int i = 1; i <= n; i++) {
    queue.push(i);
  }
  vector<int> discarded_cards;
  while (queue.size() > 1) {
    discarded_cards.push_back(queue.front());
    queue.pop();
    queue.push(queue.front()); 
    queue.pop();
  }
  int last_card = queue.front();
  discard.push_back(discarded_cards);
  lastcard.push_back(last_card);
}
void show(vector<int> &dis){
    if(dis.empty()) {
        cout<<"Discarded cards:\n";
        return;
    }
    cout<<"Discarded cards:";
    vector<int>::iterator it;
    cout<<" ";
    for(it = dis.begin();it!=dis.end()-1;it++)
        cout<<*it<<", ";
    cout<<*it<<"\n";
}
using namespace std;
int main() {
    int n,c =0;
    vector< vector<int> > discard;
    vector<int> last_card;
    while(cin>>n){
        if (n==0) break;
        find_sequence(n,discard,last_card);
        c++;
    }
    for (int i = 0; i < c; i++)
    {
        show(discard[i]);
        cout<<"Remaining card: "<<last_card[i]<<"\n";
    }
    
    
}