#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node_t;
typedef node_t stack_t;
stack_t *push(stack_t*s,int v){
    stack_t *node =(stack_t*)malloc(sizeof(stack_t));
    node->data = v;
    node->next =NULL;

    node->next = s;
    s = node;
    return s;
}

void top(stack_t *s){
     if(s == NULL)
     {
      printf("Stack is empty.\n");
      return;
    } 
    printf("%d\n",s->data);
}
stack_t *pop(stack_t * s){
        if(s == NULL)
            return NULL;
        stack_t *temp = s;
        s = s->next;
        free(temp);
        return s;
}
void empty(stack_t*s)
{
    if(s == NULL)
      printf("Stack is empty.\n"); 
    else
        printf("Stack is not empty.\n");    
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
    stack_t *s = NULL;
    int n,i,command,value;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch (command)
        {
        case 1:
            scanf("%d",&value);
            s = push(s,value);
            break;
        case 2:
            top(s);
            break;
        case 3:
            s = pop(s);
            break;
        case 4:
            empty(s);
            break;
        case 5:
            size(s);
            break;
        }
    }
    return 0;
}
