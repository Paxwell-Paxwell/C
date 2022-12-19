#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, start_row, start_col, end_row, end_col;
char maze[101][101];
int visited[101][101];
int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int solve(int row, int col)
{
    visited[row][col] = 1;

    if (row == end_row && col == end_col)
        return 1;

    for (int i = 0; i < 4; i++)
    {
        int next_row = row + directions[i][0];
        int next_col = col + directions[i][1];

        if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n)
            continue;
        if (maze[next_row][next_col] == '#')
            continue;
        if (visited[next_row][next_col])
            continue;

        if (solve(next_row, next_col))
        {
            if (row != start_row || col != start_col)
                maze[row][col] = '.';
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &maze[i][j]);
            if (maze[i][j] == '\n')
                scanf("%c", &maze[i][j]);
            if (maze[i][j] == 'S')
            {
                start_row = i;
                start_col = j;
            }
            else if (maze[i][j] == 'G')
            {
                end_row = i;
                end_col = j;
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    solve(start_row, start_col);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
    return 0;
}

/*
12
############
#   #      #
# # # #### #
### #    # G
#    ### # #
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
##########S#
 */
