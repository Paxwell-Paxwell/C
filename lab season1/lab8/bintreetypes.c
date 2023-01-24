#include<stdio.h>
#include<stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
}node_t;

typedef node_t tree_t;
#endif
typedef struct qq{
    tree_t *data;
    struct qq *next;
} q_t;
typedef q_t queue_t;
queue_t * enqueue(queue_t *q,tree_t * t)
{
    q_t *newnode = (q_t *)malloc(sizeof(q_t));
    q_t *lastnode = q;
    newnode ->data = t;
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
    q = q->next;
    free(tmp);

    return q;
}

int is_full(tree_t*t){
        int child=0,full;
        if (t == NULL)
        {
            return 1;
        }
        if(t!=NULL&&t->left!=NULL)
            child++;
        if(t!=NULL&&t->right!=NULL)
            child++;
        if(child ==1)
            return 0;
        full = is_full(t->left);
        if (full!=1)
            return full;
        return is_full(t->right);
}
int size(tree_t *t){
    if(t == NULL)
    return 0;
    return size(t->left)+size(t->right)+1;
}
int height(tree_t*t){
    int hl,hr;
    if (t==NULL)
        return -1;
    hl = height(t->left);
    hr = height(t->right);
    return (hl>hr) ? hl+1:hr+1;
}
int power(int num,int degree){
    if (degree == 0)
        return 1;
    return num*power(num,degree-1);
}
int is_complete(tree_t*t){
    if(t==NULL)
        return 1;
    int flag = 0;
    queue_t *q=NULL;
    q = enqueue(q,t);
    while(q!=NULL)
    {
        //printf("1");
        tree_t *tmp = q->data;
        q = dequeue(q);
        if (tmp->left!=NULL){
            if(flag==1)
                return 0;
            q = enqueue(q,tmp->left);
        }
        else
            flag =1;
        if(tmp->right!=NULL){
            if(flag==1)
                return 0;
            q = enqueue(q,tmp->right);
        }
         else
            flag =1;
    }
    return 1;
}
int is_perfect(tree_t*t){
    int h = height(t),s = size(t);
    if (s == power(2,h+1)-1)
        return 1;
    return 0;
}
int is_degenerate(tree_t*t){
        int child=0,full;
        if (t == NULL)
        {
            return 1;
        }
        if(t!=NULL&&t->left!=NULL)
            child++;
        if(t!=NULL&&t->right!=NULL)
            child++;
        if(child ==2)
            return 0;
        full = is_degenerate(t->left);
        if (full!=1)
            return full;
        return is_degenerate(t->right);
}
int is_skewed(tree_t*t){
    if(is_degenerate(t))
    {
        int r=0,l=0;
        tree_t *pos =t ;
        while (pos!=NULL)
        {
            pos =pos->left;
            l++;
        }
        pos =t;
        while(pos!=NULL)
        {
             pos =pos->right;
            r++;
        }
        if (r==size(t)||l==size(t))
            return 1;
        else
            return 0;
    }
    return 0;
}
int main(void){
    tree_t *t = NULL;
    int n,i;
    int parent,child;
    int branch;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&parent,&child,&branch);
        t = attach(t,parent,child,branch);
    }
    //printf("%d\n",size(t));
    printf("%d %d %d %d %d\n",is_full(t),is_perfect(t),is_complete(t),is_degenerate(t),is_skewed(t));
    return 0;
} 

