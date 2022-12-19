#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node *next;
} node_t;
typedef node_t stk_t;
void push(stk_t**s,char v){
    stk_t *node =(stk_t*)malloc(sizeof(stk_t));
    node->data = v;
    node->next =NULL;

    node->next = *s;
    *s = node;
}

char top(stk_t *s){
    return s->data;
}
void pop(stk_t ** s){
        if(*s == NULL)
            *s=NULL;
        stk_t *temp = *s;
        *s = (*s)->next;
        free(temp);
}
int correct(stk_t*s)
{
    if(s == NULL)
      return 1; 
    else
        return 0;    
}

int main(){
    stk_t *s = NULL;
    int n ;
    scanf("%d",&n);
    char ex;
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&ex);
        if (ex==')')
        {
            if(top(s)=='(')
            {
                pop(&s);
            }
            else
                push(&s,ex);
        }
        else if (ex=='}')
        {
            if(top(s)=='{')
            {
                pop(&s);
            }
            else
                push(&s,ex);
        }
        else if(ex==']')
        {
            if(top(s)=='[')
            {
                pop(&s);
            }
            else
                push(&s,ex);
        }
        else
            push(&s,ex);
    }
    printf("%d",correct(s));
    return 1;
}