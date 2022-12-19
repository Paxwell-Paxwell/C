#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node_t;
node_t *append(node_t *head) {
    int data;
    scanf(" %d",&data);
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    node_t *lastnode = head;
    newnode ->data = data;
    newnode ->next = NULL;
    if (head == NULL)
        return newnode;
    else{
        while(lastnode ->next != NULL)
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
    }
    return head;
}
void get(node_t *head)
{
    int index;
    scanf(" %d",&index);
    node_t *current =head;
    int c= 0;
    while(current != NULL){
        if (c== index)
        {
            printf("%d\n",current->data);
        }
        c++;
        current = current->next;
    }
    return;
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
node_t *reverse(node_t *head_ref)
{
    node_t * prev = NULL;
    node_t * current = head_ref;
    node_t * next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
    return head_ref;
}
node_t *cut(node_t *head){
    int f,l ;
    scanf("%d %d",&f,&l);
    node_t *current = head;
    node_t *next;
    int c= 0;
    while(c<f){
        next = current->next;
        free(current);
        current = next;
        c++;
    }
    head = current;
    while(c <l){
        next = current->next;
        current = next;
        c++;
    }
    next= current->next;
    current->next = NULL;
    current= next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    return head;
}
int main(void){
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}