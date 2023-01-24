#include<stdio.h>
#include<math.h>
int r = 1;
void maxMin(int*max,int*min)
{
    if(*max >= *min){
        return;
    }
    int temp = *min;
    *min = *max;
    *max = temp;
}
int cestate(int m ,int n)
{   
    if (m==0||n==0)
        return 1;
    maxMin(&n,&m);
    int max ,i;
    for( i = 0; m >= pow(2,i);i++ ){}
    max = i-1;
    int a = m -pow(2,max);
    int b = n- pow(2,max);
    if(a != 0)
    {
    r += 1;
    cestate(a,n);}
    if(b !=0 )
    {
    r += 1;
    cestate(b,pow(2,max));}
    
 return 1;
}

int main()
{
    int m ,n;
    scanf("%d %d",&m,&n);
    if (m!=0&&n!=0){
    cestate(m,n);
    printf("%d",r);}
    else
    printf("0");
}