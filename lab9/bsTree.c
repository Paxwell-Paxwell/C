#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    
} node_t;

typedef node_t bst_t;
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
bst_t * insert(bst_t *t,int data){
    if (t == NULL)
        return newNode(data);
    if (data < t->data)
        t->left = insert(t->left,data);
    else if (data > t->data)
        t->right = insert(t->right,data);
    return t;
}
bst_t * smin(bst_t *t)
{
    bst_t *pos = t;
    while(pos&&pos->left != NULL)
        pos = pos->left;
    return pos;
}
bst_t * smax(bst_t *t)
{
    bst_t *pos = t;
    while(pos&&pos->right != NULL)
        pos = pos->right;
    return pos;
}
bst_t * delete(bst_t * t,int data){
    if( t == NULL)
        return t;
    if (data < t->data)
        t->left = delete(t->left,data);
    else if (data > t->data)
        t->right = delete(t->right,data);
    else{
        if (t->left == NULL)
        {
            bst_t *temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == NULL)
        {
            bst_t *temp = t->left;
            free(t);
            return temp;
        }

        bst_t *temp = smin(t->right);
        t->data = temp->data;
        t->right = delete(t->right,temp->data);
    }
    return t;
}   
int find(bst_t *t,int data){
    if (t == NULL)
        return 0;
    if (data < t->data)
       return find(t->left,data);
    else if (data > t->data)
        return find(t->right,data);
    return 1;
}
int findmax(bst_t *t){
    return smax(t)->data;
}
int findmin(bst_t *t){
    return smin(t)->data;
}
int main(void){
    bst_t *t = NULL;
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
            scanf("%d",&data);
            printf("%d\n", find(t,data));
            break;
        case 4:
            printf("%d\n", findmin(t));
            break;
        case 5:
            printf("%d\n", findmax(t));
            break;
        }
    }
    return 0;
}