#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int a = 1;
    if (num == 0)
        a =0;
    for (int i=2;i<=sqrt(num);i++)
    {
        if (num%i == 0)
            a = 0;
    }
    printf("%d",a);
}