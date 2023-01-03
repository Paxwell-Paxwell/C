#include <iostream>
using namespace std;
int main(){
    int n=0,s=0,w=0,e=0;
    char command;
    while(1) {
        scanf("%c",&command);
        if (command == '\n'){
                break;
        }
        switch (command)
        {
        case 'N':
            n++;
            break;
        case 'E':
            e++;
            break;
        case 'S':
            s++;
            break;
        case 'W':
            w++;
            break;
        default:
            break;
        }
    }
    int l;
    cin>>l;
    if(n<s)swap(n,s);
    if(e<w)swap(e,w);
    while(l)
    {
        
        l--;
        if(s!=0)s--;
        else if(w!=0)w--;
        else if(n!=0)n--;
        else if(e!=0)e--;
    }
    int sum=abs(n-s)+abs(w-e);
    cout<<sum*2;
    return 0;
}