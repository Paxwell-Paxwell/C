#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,A,B,n;
    scanf("%lf %lf %lf %lf %lf",&a,&b,&A,&B,&n);
    double x = (b-a)/n,fx ,fx1;
    double area = 0,i = a,j = 0 ;
    while(j<n)
    {
        fx = A*sin(M_PI*i/B);
        fx1 = A*sin(M_PI*(i+x)/B);
        area += 0.5*(fx+fx1)*x;
        i += x;
        //printf("%.5lf\n",area);
        j++;
    }
    printf("%.5lf",area);
    return 0;
}