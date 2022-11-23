#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 99999 
int find(int P[], int i)
{
    while (P[i] != i)
        i = P[i];
    return i;
}
void union1(int P[], int i, int j)
{
    int a = find(P, i);
    int b = find(P, j);
    P[a] = b;
}
void kruskal(int V, int G[V][V])
{
    int i, j, P[V], sum = 0, edge_no = 0, x, y, min;
    for (i = 0; i < V; i++)
        P[i] = i;
    while (edge_no < V - 1)
    {
        min = INT_MAX;
        x = 0;
        y = 0;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (find(P, i) != find(P, j) && G[i][j] < min)
                {
                    min = G[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        union1(P, x, y);
        printf("Edge from %d to %d Cost :- %d\n", x, y, G[x][y]);
        sum += G[x][y];
        edge_no++;
    }
    printf("Minimum cost of spanning tree :- %d", sum);
}

int main()
{
    int vertices;
    int edge;
    printf("enter number of vertices : ");
    scanf("%d", &vertices);
    printf("enter number of edge : ");
    scanf("%d", &edge);
    int graph[vertices][vertices];
    int u;
    int v;
    int w;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < edge; i++)
    {
        printf("enter source : ");
        scanf("%d", &u);
        printf("enter target : ");
        scanf("%d", &v);
        printf("Enter weight : ");
        scanf("%d", &w);
        graph[u][v] = graph[v][u] = w;
    }
    kruskal(vertices, graph);
    return 0;
}