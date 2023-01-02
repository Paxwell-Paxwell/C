#include <vector>
#include <iostream>
using namespace std;
int main(){
    int N_E[2];
    int S_W[2];
    fill(N_E,N_E+2,0);
    fill(S_W,S_W+2,0);

    char command;
    while(1) {
        scanf("%c",&command);
        if (command == '\n'){
                break;
        }
        switch (command)
        {
        case 'N':
            N_E[0]++;
            break;
        case 'E':
            N_E[1]++;
            break;
        case 'S':
            S_W[0]++;
            break;
        case 'W':
            S_W[1]++;
            break;
        default:
            break;
        }
    }
    int l;
    cin>>l;
    int n=0,r1=0,r2=0;
    while(n < l)
    {
        if(r1<2){
            if(N_E[r1]==0||S_W[r1]==0){
                r1++;
                continue;
            }
            int *min=(N_E[r1]<=S_W[r1])? N_E:S_W;
            min[r1]--;
            n++;
        }
        else if(r1>=2){

            if(N_E[r2]==0&&S_W[r2]==0){
                r2++;
                continue;
            }
            int *max=(N_E[r2]>=S_W[r2])? N_E:S_W;
            max[r2]--;
            n++;

        }
    }
    int sum=0;
    for(int i=0;i<2;i++){
        sum+= abs(N_E[i]-S_W[i]);
    }
    cout<<sum*2;
    return 0;
}