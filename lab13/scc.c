#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node_t;
typedef node_t stk_t;
typedef struct scc{
    int *strong;
    int num_scc;
}scc_t;
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void start_graph(int** graph,int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
}
void connect_node(int **graph,int u,int v,int w){
    graph[u][v] = w;

}
void set_all(int *visited,int num,int n){
    for(int i=0;i<n;i++){
        visited[i]=num;
    }
}
void push(stk_t**s,int v){
    stk_t *node =(stk_t*)malloc(sizeof(stk_t));
    node->data = v;
    node->next =NULL;

    node->next = *s;
    *s = node;
}
void pop(stk_t ** s){
        if(*s == NULL)
            *s=NULL;
        stk_t *temp = *s;
        *s = (*s)->next;
        free(temp);
}
int top(stk_t *s){
    return s->data;
}
int size(node_t* s)
{
    int count = 0; 
    node_t* current = s; 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void dfs(int **graph,int *visited,int str,int c_n,stk_t **dfs_work){
    visited[str] = 1;
    push(dfs_work,str);
    for (int v=0;v <c_n;v++){
        if (!visited[v]&&graph[str][v]==1){
            dfs(graph,visited,v,c_n,dfs_work);
        }
    }
    return;
}
void fillorder(int **graph,int *visited,int str,int n,stk_t **fill ){
    visited[str] = 1;
    for(int v=0;v<n;v++){
        if(!visited[v]&&graph[str][v]){
            fillorder(graph,visited,v,n,fill);
        }
    }
    push(fill,str);
    return;
}
int *result_dfs(int**graph,int *visited,int n,int start,int *count){
    int *dfs_work = (int *)malloc(sizeof(int)*n);
    stk_t *dfsnow = NULL;
    set_all(dfs_work,-1,n);
    dfs(graph,visited,start,n,&dfsnow);
    *count = size(dfsnow);
    for(int i=(*count-1);i>=0;i--){
        dfs_work[i]=top(dfsnow);
        pop(&dfsnow);
    }
    return dfs_work;

}
int **GT(int **graph,int n){
    int **tp_graph=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        tp_graph[i] = (int *)malloc(sizeof(int)*n);
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            tp_graph[i][j] = graph[j][i];
        }   
    }
    return tp_graph;
}
scc_t  max_scc(scc_t * scc,int c){
    int max =0,max_index;
    for(int i=0;i<c;i++){
        if(scc[i].num_scc > max){
            max = scc[i].num_scc; max_index = i;
        }
    }
    return scc[max_index];
}
int main(){
    int n,m;
    scanf("%d %d ",&n,&m);
    int **graph=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        graph[i] = (int *)malloc(sizeof(int)*n);
    }
    start_graph(graph,n);
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        connect_node(graph,u,v,1);
    }
    int visited[n];
    set_all(visited,0,n);
    stk_t *fill=NULL;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            fillorder(graph,visited,i,n,&fill);
        }
    }
    set_all(visited,0,n);
    graph = GT(graph,n);
    int c=0;
    scc_t scc[n];
    for(int i=0;i<n;i++){
        int top_re = top(fill);
        if (!visited[top_re]){
            int count=0;
            scc[c].strong = result_dfs(graph,visited,n,top_re,&count);
            scc[c].num_scc = count;
            
            c++;
        }
        pop(&fill);
    }
    scc_t max = max_scc(scc,c);
    qsort(max.strong,max.num_scc, sizeof(int), cmpfunc);
    for(int i=0;i<max.num_scc;i++){
        printf("%d ",max.strong[i]);
    }
    printf("\n");
}
