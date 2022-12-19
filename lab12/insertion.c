#include<stdio.h>

void swap(int *num1,int *num2){
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
int find_ifmin(int end,int *data)
{
    for(int i=0;i<end;i++){
        if (data[end]<=data[i])
            return i;
    }
    return -1;
}
void insertion(int start,int end,int*data){
    for(int i=end;i>start;i--){
        swap(&data[i],&data[i-1]);
    }
}
void print_insertion(int *data,int n){
    for(int i=0;i<n;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
}
int main(){
    int n ,data[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
        scanf(" %d",&data[i]);
    }
    int end;
    for(end =1;end<n;end++)
    {
        if(find_ifmin(end,data)==-1){
            print_insertion(data,n);
            continue;}
        else
            {
                insertion(find_ifmin(end,data),end,data);
            } 
        print_insertion(data,n);
    }
    if(n==1){
        print_insertion(data,n);
    }
    return 1;
}