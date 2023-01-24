#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct word_data
{
    char word[50];
    char sortword[50];
}word_data;
void merge(char *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    char L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;j = 0; k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(char *arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void anagrame(word_data *data,char *str,int m){
    mergeSort(str,0,strlen(str)-1);
    for(int i=0;i<m;i++){
        if(strcmp(data[i].sortword,str)==0)
        {
            printf("%s ",data[i].word);
        }
    }
    printf("\n");
}
int main(){
    int m,n;
    scanf("%d %d", &m,&n);
    word_data data[50000];
    for(int i=0;i<m;i++){
        scanf(" %s",data[i].word);
        char sortword[50] ;
        strcpy(sortword,data[i].word);
        mergeSort(sortword,0,strlen(sortword)-1);
        strcpy(data[i].sortword,sortword);
    }
    char word[50];
    for(int i=0;i<n;i++){
         scanf(" %s",word);
         anagrame(data,word,m);
    }

}
