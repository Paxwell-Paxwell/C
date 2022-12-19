#include<stdio.h>
#include<string.h>
int main()
{
    char sum_cstr[30000][50];
    char string[100000];
    scanf("%[^\n]s",string);
    char * token = strtok(string, " ");
   int i =0 ;
   while( token != NULL ) {
      strcpy(sum_cstr[i],token);
      token = strtok(NULL, " ");
      i ++;
   }
   while(i--)
   {
    printf("%s ",sum_cstr[i]);
   }
   return 0;

}