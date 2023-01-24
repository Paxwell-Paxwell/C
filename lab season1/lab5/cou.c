#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 int check_k(int num,int k){
    if (num%k == 0)
    {
        return 1;
    }
    char miko[1000];
    sprintf(miko,"%d",num);
    for(int i=0;i<strlen(miko);i++)
    {
        if ((k+'0')==miko[i])
        {
            return 1;
        }
    }
    return 0;
}
int cou(int*num,int n)
{
    int c = 0 ;
    for(int i=0;i<n;i++)
    {
        if (num[i]<0)
            continue;
        c++;
    }
    return c;
}
int main(){
    int num[10000];
    int n,k;
    int mik;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf(" %d",&num[i]);
    }
    int number = 1;
    int a;
    while(1){
        int c =0;
        for(int i=0;i<n;i++)
        {
            if (num[i]<0)
                continue;
            if(check_k(number,k))
            {
                //printf("%d,%d,drink\n",i+1,number);
                num[i]--;}
            //else
                //printf("%d,%d,not drink\n",i+1,number);
            if (cou(num,n)==1)
            {
                break;
            }
            c++;
            number ++;
        }
        if (cou(num,n)==1)
            {
                break;
            }
    }
    for(int i=0;i<n;i++)
    {
        if(num[i]>=0)
            {
                a= i+1;
                printf("%d",a);
                break;
            }
    }
}