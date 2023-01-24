#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char *word;
    int freq;
    struct node *left;
    struct node *right;
} tree_t;

typedef struct heap {
    tree_t **node;
    int last_index;
} heap_t;

heap_t *init(int n) {
    tree_t **anode = (tree_t**)malloc(sizeof(tree_t*) * (n+1));
    heap_t *new = (heap_t *)malloc(sizeof(heap_t));
    new->node = anode;
    new->last_index = 1;
    return new;
}
void swap(tree_t ** a,tree_t **b){
 tree_t temp = **a;
 **a = **b;
 **b = temp;
}
int parent(int i){return (i)/2;}
int cleft(int i){return (2*i);}
int cright(int i){return (2*i+1);}
void balance(int i,tree_t **data){
    if(i==1)
        return;
    if(data[parent(i)]->freq>data[i]->freq)
    {
        swap(&data[parent(i)],&data[i]);
        balance(parent(i),data);
    }
    return;
}
void basicin(heap_t *min_heap, char *word, int fre) {
    int lastempty = min_heap->last_index;
    tree_t *add;
    add = (tree_t*)malloc(sizeof(tree_t));
    add->word = word;
    add->freq = fre;
    min_heap->node[lastempty] = add;
    balance(lastempty, min_heap->node);
    min_heap->last_index++;
}

void insertNode(heap_t *min_heap, tree_t *t) {
    int lastempty = min_heap->last_index;
    min_heap->node[lastempty] = t;
    balance(lastempty, min_heap->node);
    min_heap->last_index++;
}
void sortmin(int i,heap_t *heap){
    int l = cleft(i);
    int r = cright(i);
    int small = i;
    if (l < heap->last_index && (heap->node[l]->freq)<(heap->node[i]->freq))
        small = l;
    if (r < heap->last_index  && (heap->node[r]->freq)<(heap->node[small]->freq))
        small = r;
    if (small != i)
    {
        swap(&(heap->node[i]),&(heap->node[small]));
        sortmin(small,heap);
    }
}

void delete_min(heap_t *min_heap) {
    if(min_heap->last_index==1)
        return;
    if(min_heap->last_index == 2)
    {
        min_heap->last_index--;
        return;}
    min_heap->node[1] = min_heap->node[min_heap->last_index-1];
    min_heap->last_index--;
    sortmin(1,min_heap);
}

void tree_get(heap_t *min_heap) {
    tree_t *first = NULL;
    tree_t *second = NULL;
    while (min_heap->last_index != 2) {
        tree_t *new = (tree_t *)malloc(sizeof(tree_t));
        first = min_heap->node[1];
        delete_min(min_heap);
        second = min_heap->node[1];
        delete_min(min_heap);
        new->word = "A";
        new->left = first;
        new->right = second;
        new->freq = first->freq + second->freq;
        insertNode(min_heap, new);
    }
}
void dfs(tree_t *t, char *w) {
    if (t!=NULL) {
    char *placeholder = "A";
    if(t->word != placeholder) printf("%s: %s\n", t->word, w);
    char w1[100], w2[100];
    strcpy(w1, w);
    strcpy(w2, w);
    strcat(w1, "0");
    strcat(w2, "1");
    dfs(t->left, w1); 
    dfs(t->right, w2);
    } 
}


int main() {
    heap_t *min_heap = NULL;
    int n=6, i, freq;
    scanf("%d", &n);
    min_heap = init(n);
    for (i=0; i<n; i++) {
        char *word = (char*)malloc(sizeof(char) * 15);
        scanf("%s %d", word, &freq);
        basicin(min_heap, word, freq);
    }
    tree_get(min_heap);
    dfs(min_heap->node[1], "");
    return 0;
}