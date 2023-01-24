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
void print_preordern(tree_t*t){
    if(t==NULL)
        return;
    printf("%d ",t->data);
    print_preordern(t->left);
    print_preordern(t->right);
}
void print_preorder(tree_t*t){
    print_preordern(t);
    printf("\n");
}
void print_postordern(tree_t*t){
    if(t==NULL)
        return;
    print_postordern(t->left);
    print_postordern(t->right);
    printf("%d ",t->data);
}
void print_postorder(tree_t*t){
    print_postordern(t);
    printf("\n");
}

void print_inordern(tree_t*t){
    if(t==NULL)
        return;
    print_inordern(t->left);
    printf("%d ",t->data);
    print_inordern(t->right);
}
void print_inorder(tree_t*t){
    print_inordern(t);
    printf("\n");
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
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);
    return 0; 
} 
// 5
// -1 1 0
// 1 2 1
// 1 3 2
// 2 4 1
// 2 5 2
// 6
// -1 1 0
// 1 2 1
// 1 3 2
// 2 4 1
// 2 5 2
// 3 6 1
// 4
// -1 1 0
// 1 2 1
// 2 3 2
// 3 4 2
// 3
// -1 1 0
// 1 2 1
// 2 3 1
// 7
// -1 1 0
// 1 2 1
// 1 3 2
// 2 4 1
// 2 5 2
// 5 6 1
// 5 7 2