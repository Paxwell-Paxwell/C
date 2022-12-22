#include <iostream>
typedef struct node{
    int data;
    struct node *next;
} node_t;
node_t *insert(node_t *head,node_t **last) {
    int data;
    scanf(" %d",&data);
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    node_t *prenode = head;
    newnode ->data = data;
    newnode ->next = NULL;
    if (head == NULL){
        *last = newnode;
        return newnode;}
    newnode->next= prenode;
    return newnode;
}
node_t *del(node_t *head,int index,node_t**last)
{
    node_t *current =head;
    int c= 1;
    while(current != NULL){
        if (index ==1)
        {
            node_t *tmp = current->next;
            if(current->next == NULL)
                *last=NULL;
            free(current);
            return tmp;
           
        }
        if(c==index-1&&current->next->next==NULL){
            node_t *tmp = current->next;
            *last=current;
            free(tmp);
            current->next=NULL;
            return head;
        }
        if(c==index-1){
            node_t *tmp = current->next;
            current->next=tmp->next;
            free(tmp);
            return head;
        }
        c++;
        current = current->next;
    }
    return head;
}
node_t *append(node_t *head,node_t **last) {
    int data;
    scanf(" %d",&data);
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode ->data = data;
    newnode ->next = NULL;
    if (head == NULL){
        *last = newnode;
        return newnode;
    }
    (*last)->next = newnode;
    return head;
}
void show(node_t *head) {
   struct node *ptr = head;
   while(ptr != NULL) {
      printf("%d ",ptr->data);
      ptr = ptr->next;
   }
   printf("\n");
   return;
}


int main(void){
    node_t *startNode,*lastnode;
    
    int n,i;
    char command;
    startNode = NULL;
    lastnode = NULL;
    scanf("%d",&n);
    int k =0;
    for(i=0;i<n;i++)
    {
        scanf(" %c",&command);
        switch (command)
        {
        case 'I':
            startNode = insert(startNode,&lastnode);
            show(startNode);
            
            k++;
            break;
        case 'D':
            int index;
            scanf(" %d",&index);
            if(index>k)
                break;
            startNode = del(startNode,index,&lastnode);
            show(startNode);
            k--;
            break;
        case 'A':
            startNode= append(startNode,&lastnode);
            show(startNode);
            k++;
            break;
        default:
            break;
        }
    }
    show(startNode);
    return 0;
}