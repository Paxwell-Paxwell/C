#include<stdio.h>
int md[] ={31,28,31,30,31,30,31,31,30,31,30,31};
int countday(int y,int m)
{
    int day = 0;
    for (int cy = 1990;cy < y;cy++)
    {
        if(cy%400 == 0|| (cy%4 == 0 && cy%100 != 0))
        {
            day += 366;
        }
        else
        {
            day  += 365;
        }
    } 
    if (y%400 == 0|| (y%4 == 0 && y%100 != 0))
        {
            md[1] = 29;
        }
    for (int i =0;i<m-1;i++)
    {
        day += md[i]; 
    }
    return day;
}
int main()
{
int year,m ;
char month[][20] = {"January","February","March",
"Aprill","May","June","July",
"August","September","October",
"November","December"} ;
printf("Enter year: ");
scanf("%d",&year);
printf("Enter month: ");
scanf("%d",&m);
printf("====================\n");
printf("%s %d\n",month[m-1],year);
printf("Sun Mon Tue Wed Thu Fri Sat\n");
int fd = countday(year,m)%7;
int j ;
    if (fd == 0) j =1 ;
    else if (fd == 1) j = 2;
    else if (fd == 2) j = 3;
    else if (fd == 3) j = 4;
    else if (fd == 4) j = 5;
    else if (fd == 5) j = 6;
    else if (fd == 6) j = 0;
int date = 1;
while(1)
{
    for (int i =0 ;i<7;i++)
    { 
        if (j>0) 
        {
            printf("    ");
            j--;
        }
       else if (date<10)
       {
            printf("  %d ",date);
            date ++;
       }
       else if (date >=10)
       {
            printf(" %d ",date);
            date ++;
       }
       if (date > md[m-1]) break;
    }
    printf("\n");
    if (date > md[m-1]) break;
    
}
}