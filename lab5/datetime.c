#include<stdio.h>
typedef struct datetime
{
    int date;
    int month;
    int year;
    int dayOfWeek;
    int hour;
    int minute;
    int second;
} datetime_t;
int checkdayyear(int y){
    if(y%400 == 0|| (y%4 == 0 && y%100 != 0))
        return 366*86400;
    else
        return 365*86400;
}
int checkyear(int y){
 if(y%400 == 0|| (y%4 == 0 && y%100 != 0))
        return 1;
 else
        return 0;
}

datetime_t createDate(int time){
    datetime_t dt;
    int cday = time/86400 ;
    int dayOfWeek = cday%7;
    int ctime = time;
    int md[] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int year = 1970;
    while(1){
        //printf("%d\n",checkdayyear(year));
        //printf("%d\n",ctime);
        if((ctime-checkdayyear(year))<0)
            break;
        ctime = ctime-checkdayyear(year);
        year++;
    }
    //printf("%d\n",ctime);
    if (checkyear(year))
        md[1] = 29;          
    else
        md[1] = 28;
    int  month = 0;
    while(1){
        if((ctime-md[month]*86400)<0)
            break;
        ctime = ctime-md[month]*86400;
        month++;
    }
    //printf("%d\n",ctime);
    int date;
    for(int i=1;i<=md[month];i++)
    {
        if((ctime-86400)<0)
            {
            date = i;
            break;}
        ctime = ctime-86400;  
    }
    //printf("%d\n",ctime);
    int hour = ctime/3600;
    ctime = ctime%3600;
    int minute = ctime/60;
    int second = ctime%60;
    dt.date = date;
    dt.month = month+1;
    dt.year = year;
    dt.dayOfWeek = dayOfWeek;
    dt.hour = hour;
    dt.minute = minute;
    dt.second =  second;
    return dt;
}
void printDate(datetime_t id){
    char dayofweek[][20] = { "Thu" ,"Fri", "Sat" ,"Sun" ,"Mon","Tue", "Wed"} ;
    char month[][5] = {"JAN","FEB","MAR",
    "APR","MAY","JUN","JUL",
    "AUG","SEP","OCT",
    "NOV","DEC"} ;
    char hour[3],minute[3],second[3];
    if (id.hour <10)
    {
        hour[0] = '0';
        sprintf(&hour[1],"%d",id.hour);
    }
    else
    {
        sprintf(hour,"%d",id.hour);
    }
    if (id.minute <10)
    {
        minute[0] = '0';
        sprintf(&minute[1],"%d",id.minute);
    }
    else
    {
        sprintf(minute,"%d",id.minute);
    }
    if (id.second <10)
    {
        second[0] = '0';
        sprintf(&second[1],"%d",id.second);
    }
    else
    {
        sprintf(second,"%d",id.second);
    }
    printf("%s %d %s %d %s:%s:%s",dayofweek[id.dayOfWeek],id.date,month[id.month-1],id.year,hour,minute,second);
}
int main(void){
    datetime_t inputDate;
    int timestamp;
    scanf("%d",&timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}
