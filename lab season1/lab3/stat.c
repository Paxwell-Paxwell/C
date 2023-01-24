#include<stdio.h>
#include<stdlib.h>
void findStats(int *nums,double *avg,int *maxi,int *mini,int n){
    double sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += nums[i];
    }
   *avg = sum/n;
   *maxi = nums[0];
   for (int i =0;i<n;i++)
   {
        if(nums[i] > *maxi ) *maxi = nums[i];
   }
   *mini = nums[0];
   for (int i=0;i<n;i++)
   {
        if(nums[i]< *mini ) *mini = nums[i];
   }
   free(nums);
}
int main(void){
    int n,i,maxi,mini;
    double avg;
    int *nums;
    scanf("%d",&n);
    nums =  (int *)malloc(sizeof(int) *n);
    for(i=0; i<n;i++)
        scanf("%d",nums+i);
    findStats(nums,&avg,&maxi,&mini,n);
    printf("%.2f %d %d",avg,maxi,mini);
    return 0;
}