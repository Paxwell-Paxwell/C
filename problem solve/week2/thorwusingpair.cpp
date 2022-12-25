#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<vector<int>, int> find_sequence(int n) {
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
  return make_pair(discarded_cards, last_card);//can use return pair<vector<int>, int>(discarded_cards, last_card);

}

void show(vector<int> &dis){
    cout<<"Discarded cards: ";
    vector<int>::iterator it;
    for(it = dis.begin();it!=dis.end()-1;it++)
        cout<<*it<<",";
    cout<<*it<<"\n";
}

int main() {
    int n,c =0;
    vector< vector<int> > discard;
    vector<int> last_card;
    while(cin>>n){
        if (n==0) break;
        pair<vector<int>, int> result = find_sequence(n);
        discard.push_back(result.first);
        last_card.push_back(result.second);
        c++;
    }
    for (int i = 0; i < c; i++)
    {
        show(discard[i]);
        cout<<last_card[i]<<"\n";
    }
    
    
}
