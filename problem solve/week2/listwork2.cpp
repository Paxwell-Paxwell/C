#include <iostream>
typedef struct node{
    int data;
    struct node *next;
} node_t;
node_t *insert(node_t *head) {
    int data;
    scanf(" %d",&data);
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    node_t *lastnode = head;
    newnode ->data = data;
    newnode ->next = NULL;
    if (head == NULL)
        return newnode;
    newnode->next= lastnode;
    return newnode;
}
node_t *del(node_t *head,int index)
{
    node_t *current =head;
    int c= 1;
    while(current != NULL){
        if (index ==1)
        {
            node_t *tmp = current->next;
            free(current);
            return tmp;
           
        }
        if(c==index-1&&current->next->next==NULL){
            node_t *tmp = current->next;
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
void show(node_t *head) {
   struct node *ptr = head;
   while(ptr != NULL) {
      printf("%d\n",ptr->data);
      ptr = ptr->next;
   }
   printf("\n");
   return;
}


int main(void){
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    int k =0;
    for(i=0;i<n;i++)
    {
        scanf(" %c",&command);
        switch (command)
        {
        case 'I':
            startNode = insert(startNode);
            k++;
            break;
        case 'D':
            int index;
            scanf(" %d",&index);
            if(index>k)
                break;
            startNode = del(startNode,index);
            k--;
            break;
        default:
            break;
        }
    }
    show(startNode);
    return 0;
}