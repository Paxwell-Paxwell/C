#include<stdio.h>
#include<string.h>
int max(int a,int b){
    int max = a;
    if (a<b)
        max = b;
    return max;
}
int min(int a,int b){
    int min = a;
    if (a>b)
        min = b;
    return min;
}
int plus(char x, char y){
	return (x - '0') + (y - '0');
}
int main(){
    char num1[10000];
    char num2[10000];
    char minnum[10000];
    char maxnum[10000];
    scanf("%s",num1);
    scanf("%s",num2);
    int strlnum1 = strlen(num1);
    int strlnum2 = strlen(num2);
    int maxstr = max(strlnum1,strlnum2);
    int minstr = min(strlnum1,strlnum2);
    for(int i=0;i<maxstr;i++)
        {
            minnum[i] = '0';
        }
    if (strlnum1 == minstr){
        strcpy(minnum+(maxstr-minstr),num1);
        strcpy(maxnum,num2);}
    else
       { 
        strcpy(minnum+(maxstr-minstr),num2);
        strcpy(maxnum,num1);
       }
    char sum[10000],temp = 0;
    int index = 0;
    for(int i = maxstr-1;i>=0;i--)
    {  
        temp += plus(minnum[i], maxnum[i]);
        sum[index] = (temp % 10) + '0';
        if(temp >= 10) temp = 1;
        else temp = 0;
        index++;
    }
    if(temp != 0){
    	sum[index] = temp + '0';
    	index++;
	}
    for(int i = index-1;i >=0;i--){
        printf("%c", sum[i]); 
}
}

