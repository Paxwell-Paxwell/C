#include<stdio.h>
#include<stdlib.h>
 
typedef struct heap{
    int *data;
    int last_index;
}heap_t;

heap_t *init_heap(int m) {
    int *ar = (int *)malloc(sizeof(int) * (m+1));
    heap_t *new = (heap_t *)malloc(sizeof(heap_t));
    new->data = ar;
    new->last_index = 0;
    return new;
}
void swap(int * a,int *b){
 int temp = *a;
 *a = *b;
 *b = temp;
}
int parent(int i){return (i)/2;}
int cleft(int i){return (2*i);}
int cright(int i){return (2*i+1);}
void sortmaxinsert(int i,int *data){
    if(i==1)
        return;
    if(data[parent(i)]<data[i])
    {
        swap(&data[parent(i)],&data[i]);
        sortmaxinsert(parent(i),data);
    }
    return;
}
void sortmax(int i,heap_t *heap){
    int l = cleft(i);
    int r = cright(i);
    int big = i;
    if (l <= heap->last_index  && heap->data[l]>heap->data[i])
        big = l;
    if (r <= heap->last_index  && heap->data[r]>heap->data[big])
        big = r;
    if (big != i)
    {
        swap(&(heap->data[i]),&(heap->data[big]));
        sortmax(big,heap);
    }
}
void insert(heap_t *max_heap,int data){  
    if (max_heap->last_index == 0)
    {
        max_heap->data[1] = data;
        max_heap->last_index++;
        return;
    }
    max_heap->data[max_heap->last_index+1] = data;
    max_heap->last_index++;
    sortmaxinsert(max_heap->last_index,max_heap->data);
    
}
void delete_max(heap_t *max_heap)
{
    if(max_heap->last_index==0)
        return;
    if(max_heap->last_index == 1)
    {
        max_heap->last_index--;
        return;}
    max_heap->data[1] = max_heap->data[max_heap->last_index];
    max_heap->last_index--;
    sortmax(1,max_heap);
}
int find_max(heap_t *max_heap){
    if (max_heap->last_index != 0)
        return max_heap->data[1];
    return -1;
}
int chindex(heap_t *max_heap,int data){
    for(int i=1;i<=max_heap->last_index;i++)
    {
        if(max_heap->data[i]==data)
            return i;
    }
    return 0;
}
void update_key(heap_t *max_heap,int old_key,int new_key)
{
    int upindex = chindex(max_heap,old_key);
    //printf("%d",upindex);
    max_heap->data[upindex] = new_key;
    sortmaxinsert(upindex,max_heap->data);
    return;
}
void bfs(heap_t*max_heap)
{
    for(int i=1;i<=max_heap->last_index;i++)
        printf("%d ",max_heap->data[i]);
    //printf("%d",max_heap->last_index);
    printf("\n");
    
    return;
}
int main(void){
    heap_t *max_heap =NULL;
    int m,n,i;
    int command,data;
    int old_key, new_key;

    scanf("%d %d",&m,&n);
    max_heap = init_heap(m);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch (command)
        {
        case 1:
            scanf("%d",&data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n",find_max(max_heap));
            break;
        case 4:
            scanf("%d %d",&old_key,&new_key);
            update_key(max_heap,old_key,new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}

