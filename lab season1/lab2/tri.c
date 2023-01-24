#include<stdio.h>
#include<math.h>
long long int fac(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return x*fac(x-1);    
}
int main()
{
    double a,s=0,c,t,as;
    scanf("%lf",&a);
    a= a*M_PI/180;
    for (int i =0,j = 1 ;i <10;i++ ,j += 2)

    {
        s += pow(-1,i)*pow(a,j)/fac(j);
    }
    c = sqrt(1-pow(s,2));
    t = s/c;
    printf("%.14lf %.14lf %.14lf",s,c,t);
    return 0;
}