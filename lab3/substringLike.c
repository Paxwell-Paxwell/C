#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ch(int nc,int n,int e,char *lstr,char *str,char *sub)
{
    int i = 0;
    while(i<(nc))
    {
        if(i<= nc-n)
        {
        int same = 0;
        for(int j=i;j<(n+i);j++)
            { 
            if (lstr[j] == str[j-i]) same ++;
            }
        if (same >= n-e)
            {
            char *s;
            s = (char *)malloc(sizeof(char)*(n+3));
            s[0]= '[' ,s[n+1] = ']';
            for(int j=i;j<i+n;j++)
                {
                
                if (lstr[j] == str[j-i]) s[j-i+1] = str[j-i];
                else if((lstr[j] != str[j-i])) s[j-i+1] = '?';
                }
            strncat(sub,s,n+2);
            i += n;
            free(s);
            } 
        else if (same < n-e)
            {
            strncat(sub,&lstr[i],1);
            i ++;
            }
        }
        else
        {
            strncat(sub,&lstr[i],1);
            i ++;
        }
    }
}
int main()
{
    int nc,n,e;
    scanf("%d %d %d",&nc,&n,&e);
    char lstr[10000];
    scanf("%s",lstr);
    char *str;
    str = (char *)malloc(sizeof(char)*(n+1));
    scanf("%s",str);
    char sub[10000] = "";
    ch(nc, n, e,lstr,str,sub);
    printf("%s",sub);
    free(str);
}
//acababababcbababsuuu