#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    float data;
    struct node *next;
} node_t;
typedef node_t stk_t;
void push(stk_t**s,float v){
    stk_t *node =(stk_t*)malloc(sizeof(stk_t));
    node->data = v;
    node->next =NULL;

    node->next = *s;
    *s = node;
}

float top(stk_t *s){
     if(s == NULL)
     {
      //printf("Stack is empty.\n");
      return 0;
    } 
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
        float a,b;
        if (ex=='+')
        {
            b=top(s);
            pop(&s);
            a=top(s);
            pop(&s);
            push(&s,a+b);
        }
        else if (ex=='-')
        {
            b=top(s);
            pop(&s);
            a=top(s);
            pop(&s);
            push(&s,a-b);
        }
        else if(ex=='*')
        {
            b=top(s);
            pop(&s);
            a=top(s);
            pop(&s);
            push(&s,a*b);
        }
        else if(ex=='/')
        {
            b=top(s);
            pop(&s);
            a=top(s);
            pop(&s);
            push(&s,a/b);
        }
        else
            push(&s,ex-'0');
    }
    printf("%.2f",top(s));
    return 1;
}