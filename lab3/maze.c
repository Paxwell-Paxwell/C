#include<stdio.h>
#include<stdlib.h>
char maze[100][100] ;
int **visited;
int n;
int start_row;
int start_col;
char c;
enum terrain{
    empty,
    wall,
    goal,
    crumb
};
void alloc_visited()
{
    visited = (int **)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++)
    {
        visited[i] = (int*)malloc(sizeof(int)*n);}
}
int traverseMaze(int row,int col){
    int *current = &visited[row][col];
    if (*current == goal)
    {
        return 1;
    }
    if (*current == empty){
        *current = wall;
        if (traverseMaze(row,col-1)){
            *current = crumb;
            return 1;
        }
        if (traverseMaze(row+1,col)){
            *current = crumb;
            return 1;
        }
        if (traverseMaze(row,col+1)){
            *current = crumb;
            return 1;
        }
        if (traverseMaze(row-1,col)){
            *current = crumb;
            return 1;
        }
    
    }
    return 0;
}
void get_visited(){
    alloc_visited();
    for(int i=0;i<n;i++)
    {
        for (int j=0; j<n ;j++)
        {
            if (maze[i][j] == '#')
            {
                visited[i][j] =wall;
        
            }else if(maze[i][j]=='G') {
                visited[i][j] =goal;
            }else visited[i][j] = empty;
        }
    }
}
void print_visited(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_maze(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void get_maze(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%c",&c);
            if (c == '\n')
            {
                scanf("%c",&c);
            }
            maze[i][j] = c ;
            if (c=='S'){
                start_row = i;
                start_col = j;
            }
        }
    }
}
void add_crumbs(){
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
                if ((visited[i][j]== crumb)&&(maze[i][j] !='S'))
                {
                    maze[i][j]= '.';
                }

        }
    
    }
}
int main(){
    scanf("%d",&n);
    get_maze();
    get_visited();
    traverseMaze(start_row,start_col);
    add_crumbs();
    print_maze();
    for (int i=0;i<n;i++)
    {
        free(visited[i]);
    }
    free(visited);
    return 0;
}