
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
int minDistance(int V,int *dist, bool *sptSet)
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
void printSolution(int dist[],int V)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}
void printbool(bool dist[],int V)
{
    printf("Vertex \t\t bool\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}
void dijkstra(int V,int **graph, int src,int node)
{
    int dist[V]; 
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V -1; count++) {
        int u = minDistance(V,dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    //printSolution(dist,V);
    //printbool(sptSet,V);
    if(dist[node]==INT_MAX)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n",dist[node]);
}
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int **graph=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        graph[i] = (int *)malloc(sizeof(int)*n);
    }
    start_graph(graph,n);
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        connect_node(graph,u,v,w);
    }
    int s,t;
    for(int i=0;i<p;i++){
        scanf("%d %d",&s,&t);
        dijkstra(n,graph,s,t);
    }
}
