#include <vector>
#include <iostream>
using namespace std;

struct mask
{
    int score;
    int id;
};

int main(){
    vector<int> all_player;
    int c=0,n;
    cin>>n;
    vector<mask> player1_4;
    mask max;
    max.score=0;
    for(int i=0;i<4*n;i++){
        mask new_player;
        cin>>new_player.score;
        new_player.id=i+1;
        if (new_player.score>max.score){
            max=new_player;
        }
        c++;
        if(c==n){
            c=0;
            player1_4.push_back(max);
            max = *(new mask);
            max.score=0;
            

        }
    }
    if(player1_4[0].score<player1_4[1].score){
        swap(player1_4[0],player1_4[1]);
    }
    if(player1_4[2].score<player1_4[3].score){
        swap(player1_4[2],player1_4[3]);
    }
    if(player1_4[0].score<player1_4[2].score){
        swap(player1_4[0],player1_4[2]);
    }
    swap(player1_4[1],player1_4[2]);

    for (auto it = player1_4.begin(); it != player1_4.end(); it++)
    {
        cout<<(*it).id<<" ";
    }
    
    
}
