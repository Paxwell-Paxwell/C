#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
  int data;
  struct node *left;
  struct node *right; 
} node_t;

typedef node_t tree_t;
#endif

int checkchild(tree_t *t){
  if(t==NULL){
    return 0;
  } else{
    return 1;
  }
}

int check_full(tree_t *t){
  if(t!=NULL){
    return checkchild(t->left)+checkchild(t->right)==2||checkchild(t->left)+checkchild(t->right)==0? 1:0;
  }
  return 1;
}

int is_full(tree_t *t){
  if(t==NULL){
    return 1;
  }
  if(check_full(t)==0){
    return 0;
  }
  if(check_full(t->left)==1&&check_full(t->right)==1){
    return is_full(t->left)==is_full(t->right)? 1:0;
  }
  return 0;
}

int height(tree_t *t){
  if(t==NULL){
    return -1;
  }
  int hl=height(t->left);
  int hr=height(t->right);
  return hl>hr? hl+1:hr+1;
}

int is_perfect(tree_t *t){
  if(t==NULL){
    return 1;
  }
  if(height(t->left)==height(t->right)&&is_full(t)==1){
    return 1;
  }
  return 0;
}

int is_complete(tree_t *t){
  if(t==NULL){
    return 1; 
  }
  if(is_perfect(t->left)==1){
    if(height(t->left)==height(t->right)){
      return is_complete(t->right);
    }
    //is_complete(t->right);
  }
  if(is_perfect(t->right)==1){
    if(height(t->right)+1==height(t->left)){
        return is_complete(t->left);
    }
    //is_complete(t->left);
  } 
  return 0;
}

int is_degenerate(tree_t *t){
  if(t==NULL||(t->left==NULL&&t->right==NULL)){
    return 1;
  }
  
  if(checkchild(t->left)+checkchild(t->right)==1){
    if(t->left==NULL){
      return is_degenerate(t->right);
    }
    if(t->right==NULL){
      return is_degenerate(t->left);
    } 
  }
  return 0;
}

int checkskewd(tree_t *t,int childside){ //:1=left,2=right
  if(t==NULL||(t->left==NULL&&t->right==NULL)){
    return 1;
  }
  if(childside==1&&t->right==NULL){
    return checkskewd(t->left,1);
  }
  if(childside==2&&t->left==NULL){
    return checkskewd(t->right,2);
  }
  return 0;
}

int is_skewed(tree_t *t){
  if(t==NULL||(t->left==NULL&&t->right==NULL)){
    return 1;
  }
  if(t->right==NULL){
    return checkskewd(t->left,1);
  }
  else if(t->left==NULL){
    return checkskewd(t->right,2);
  }
  return 0;
}

int main(void){
  tree_t *t=NULL;
  int n, i;
  int parent,child;
  int branch; //0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0;i<n;i++){
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }
  printf("%d \n", is_full(t));
  printf("%d \n", is_perfect(t));
  printf("%d \n", is_complete(t));
  printf("%d \n", is_degenerate(t));
  printf("%d \n", is_skewed(t));
  return 0;
}
/*
7
-1 10 0
10 6 1
10 18 2
6 4 1
6 8 2
18 21 2
18 15 1

5
-1 1 0
1 2 1
1 3 2
2 4 1 
2 5 2

6 
-1 1 0
1 2 1
1 3 2
2 4 1 
2 5 2
3 6 1

4
-1 1 0
1 2 1
2 3 2
3 4 2

3
-1 1 0
1 2 1
2 3 1

7
-1 1 0
1 2 1
1 3 2
2 4 1
2 5 2
5 6 1
5 7 2
*/