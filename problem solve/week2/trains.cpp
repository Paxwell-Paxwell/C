#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main() {
   int M;
   cin>>M;
   char com;
   vector< list<int> > platform(M);
   fill(platform.begin(), platform.end(), list<int>());
   for(int k=0;k<M;k++){
        cin>>com;
        switch (com)
        {
        case 'N':
            int x,idx;
            cin>>x>>idx;
            platform[idx].push_back(x);
            break;
        case 'M':
            int i,j;
            cin>>i>>j;
            platform[j].splice(platform[j].end(),platform[i]);
            platform[i].clear();
            break;
        default:
            break;
        }
   }
   for (int i = 0; i < M; i++)
   {
        if(platform[i].empty())
            continue;
        list<int>::iterator it;
        for(it = platform[i].begin();it != platform[i].end();it++)
            cout<<*it<<"\n";        
   }
   
}