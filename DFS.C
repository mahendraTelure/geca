// Title – Write a program for Depth First search and Breadth First search.

#include <stdio.h>
void DFS(int);
int G[10][10], visited[10], n;
void main()
{
    int i, j;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    printf("\nEnter adjecency matrix of the graph:");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
}
void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(j);
}

/*
OUTPUT:
Enter number of vertices:2

Enter adjecency matrix of the graph:10 12
14
18

0
Process returned 2 (0x2)
execution time : 10.866 s Press any key to continue.
*/
