#include<stdio.h>
#include <string.h>

int main() {
   char string[50] ;
   scanf("%s",string);
   // Extract the first token
   char * token = strtok(string, " ");
   // loop through the string to extract all other tokens
   int i =0 ;
   while( token != NULL ) {
      printf( "%s ", token ); //printing each token
      token = strtok(NULL, " ");
      i ++;
   }
   
}