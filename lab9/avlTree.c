#include<stdio.h>
#include<stdlib.h>
#include <week9.h>

#ifndef __avl_tree__
tydef struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t avl_t;
#endif
avl_t* newNode(int data)
{
    avl_t* node = (avl_t*)malloc(sizeof(avl_t));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}
int height(avl_t *t)
{
    if(t == NULL)
        return 0;
    return t->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
avl_t *rightRotate(avl_t*t)
{
    avl_t *b =t->left;
    avl_t *t2 = b->right;

    b->right = t;
    t->left = t2;

    t->height = max(height(t->left),height(t->right))+1;
    b->height = max(height(b->left),height(b->right))+1;
    return b;
}
avl_t *leftRotate(avl_t*t)
{
    avl_t *b =t->right;
    avl_t *t2 = b->left;

    b->left = t;
    t->right = t2;

    t->height = max(height(t->left),height(t->right))+1;
    b->height = max(height(b->left),height(b->right))+1;
    return b;
}
int getBalance(avl_t *t)
{
    if (t == NULL)
        return 0;
    return height(t->left) - height(t->right);
}
avl_t* insert(avl_t* t, int data)
{
    if (t == NULL)
        return newNode(data);
 
    if (data < t->data)
        t->left  = insert(t->left, data);
    else if (data > t->data)
        t->right = insert(t->right, data);
    t->height = 1 + max(height(t->left), height(t->right));
 
    int balance = getBalance(t);
    if (balance > 1 && data < t->left->data)
        return rightRotate(t);
    if (balance < -1 && data > t->right->data)
        return leftRotate(t);

    if (balance > 1 && data > t->left->data)
    {
        t->left =  leftRotate(t->left);
        return rightRotate(t);
    }
    if (balance < -1 && data < t->right->data)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
    return t;
}
avl_t * smin(avl_t *t)
{
    avl_t *pos = t;
    while(pos&&pos->left != NULL)
        pos = pos->left;
    return pos;
}
avl_t* delete(avl_t* t, int data)
{
    if (t == NULL)
        return t;
    if ( data < t->data )
        t->left = delete(t->left, data);
    else if( data > t->data )
        t->right = delete(t->right, data);
    else
    {
        if( (t->left == NULL) || (t->right == NULL) )
        {
            avl_t *temp = t->left ? t->left : t->right;
            if (temp == NULL)
            {
                temp = t;
                t = NULL;
            }
            else 
             *t = *temp; 
            free(temp);
        }
        else
        {
            avl_t * temp = smin(t->right);
            t->data = temp->data;
            t->right = delete(t->right, temp->data);
        }
    }
    if (t == NULL)
      return t;
    t->height = 1 + max(height(t->left), height(t->right));
    int balance = getBalance(t);
    if (balance > 1 && getBalance(t->left) >= 0)
        return rightRotate(t);
    if (balance > 1 && getBalance(t->left) < 0)
    {
        t->left =  leftRotate(t->left);
        return rightRotate(t);
    }
    if (balance < -1 && getBalance(t->right) <= 0)
        return leftRotate(t);
    if (balance < -1 && getBalance(t->right) > 0)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
 
    return t;
}
int main(void){
    avl_t *t = NULL;
    int n,i;
    int command ,data;

    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&command);
        switch (command)
        {
        case 1:
            scanf("%d",&data);
            t = insert(t,data);
            break;
        case 2:
            scanf("%d",&data);
            t = delete(t,data);
            break;
        case 3:
            print_tree(t);
            break;
        }
    }
    return 0;
}