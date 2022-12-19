#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node_t;
typedef node_t queue_t;
queue_t * enqueue(queue_t *q,int v)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    node_t *lastnode = q;
    newnode ->data = v;
    newnode ->next = NULL;
    if (q == NULL)
        return newnode;
    else{
        while(lastnode ->next != NULL)
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
    }
    return q;
}
queue_t * dequeue(queue_t *q)
{
    if (q==NULL){
        printf("Queue is empty.\n");
        return NULL;}
    queue_t *tmp = q;
    printf("%d\n",q->data);
    q = q->next;
    free(tmp);

    return q;
}
void show(node_t *head) {
   struct node *ptr = head;
   if (head==NULL){
        printf("Queue is empty.\n");
        return;}
   while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr = ptr->next;
   }
   printf("\n");
   return;
}
void empty(queue_t*s)
{
    if(s == NULL)
        printf("Queue is empty.\n"); 
    else
        printf("Queue is not empty.\n");    
}
void size(node_t* s)
{
    int count = 0; 
    node_t* current = s; 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("%d\n",count);
}
int main(void){
    queue_t *q = NULL;
    int n,i,command,value;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch (command)
        {
        case 1:
            scanf("%d",&value);
            q = enqueue(q,value);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            show(q);
            break;
        case 4:
            empty(q);
            break;
        case 5:
            size(q);
            break;
        }
    }
    return 0;
}