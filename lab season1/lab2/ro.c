#include <stdio.h>
#include <math.h>
int main(){
    int n,i;
    double x=0,y=0;
    char c[100000],pos='e';
    scanf("%d",&n);
    scanf("%s",&c);
    for(int i = n,j=0;i >0;i--,j++){
        if(c[j]=='L'){
            switch(pos){
                case 'n' : pos = 'w'; break;
                case 'w' : pos = 's'; break;
                case 's' : pos = 'e'; break;
                case 'e' : pos = 'n'; 
            }
        }
        else if(c[j]=='R'){
            switch(pos){
                case 'n' : pos = 'e'; break;
                case 'w' : pos = 'n'; break;
                case 's' : pos = 'w'; break;
                case 'e' : pos = 's'; 
            }
        }
        else if(c[j]=='F'){
            switch(pos){
                case 'n' : y += 1; break;
                case 'w' : x -= 1; break;
                case 's' : y -= 1; break;
                case 'e' : x += 1; 
            }
        }
    }
    printf("%.4lf",sqrt(x*x+y*y));
    return 0;
}