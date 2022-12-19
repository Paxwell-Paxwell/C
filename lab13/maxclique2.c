#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    graph[v][u] = w;
}
void delete(int **graph,int node,int n){
    for(int i=0;i<n;i++){
        if (graph[node][i]){
            graph[i][node] = 0;
        }
        graph[node][i] = 0;
    }
}
int degree(int **graph,int node,int n){
    int deg =0;
    for(int i=0;i<n;i++){
        if(graph[node][i]){
            deg++;
        }
    }
    return deg;
}
int node_min_degree(int **graph,int n){
    int min = INT_MAX,min_index;
    for(int i=0;i<n;i++){
        int deg = degree(graph,i,n);
        if (deg !=0 && deg<min){
            min_index = i; min = deg;}
        }
    return min_index;
}
int **subgraph_from_node(int **graph,int node,int n){
    int sub_node= degree(graph,node,n)+1;
    int **sub_graph=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        sub_graph[i] = (int *)malloc(sizeof(int)*n);
    }
    start_graph(sub_graph,n);
    //printf("sun_Node: %d\n",sub_node);
    int set_node[sub_node];
    int c=0;
    set_node[0] = node;
    for(int i=0;i<n;i++){
        if(graph[node][i])
        {
            c++;
            set_node[c]=i;
            
        }
    }
    for(int i=0;i<sub_node;i++){
        for(int j=0;j<sub_node;j++){
            sub_graph[set_node[i]][set_node[j]]=graph[set_node[i]][set_node[j]];
        }
    }
    return sub_graph;
}
int maxClique_forsub(int **subgraph,int n,int c_n){
    int min_index = node_min_degree(subgraph,c_n);
    int min_deg = degree(subgraph,min_index,c_n);
    if (min_deg == n-1){
        return n;
    }
    delete(subgraph,min_index,c_n);
    return maxClique_forsub(subgraph,n-1,c_n);
}
int maxClique(int **graph,int n){
    int max=1;
    for(int i=0;i<n;i++){
        int **sub = subgraph_from_node(graph,i,n);
        int count=maxClique_forsub(sub,degree(graph,i,n)+1,n);
        if (count>max){
            max = count;
        }
    }
    return max;
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
 
   printf("%d ",maxClique(graph,n));
}