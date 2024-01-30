#include<stdio.h>
#define VERTICES 6
#define INF 999

int main()
{
    int n = VERTICES;
    int cost[VERTICES][VERTICES] =
    {
        { 0, 50, 45, 10, 999, 999},
        { 999, 0, 10, 15, 999, 999},
        { 999, 999, 0, 999, 30, 999},
        { 20, 999, 999, 0, 15, 999},
        { 999, 20, 35, 999, 0, 999},
        { 999, 999, 999, 999, 3, 0}
    };
    int v = 0;

    int dist[VERTICES];
    int shortest[VERTICES];

    shortestPath(v, cost, dist, shortest, n);
    printf("Source\t\tDestination\t\tDistance\t\tPath");
    for (int i = 0; i < n; i++)
    {

        printf("\n%d\t\t\t%d\t\t%d", 0 + 1, i + 1, dist[i]);
        printShortestPath(v, i, shortest);
        printf("\n");
    }

    return 0;
}

void printShortestPath(int from, int to, int shortest[])
{
    int length = 0;
    int path[100];
    int prevNode = to;

    while (prevNode != from)       // trace back the path using the shortest array
    {
        if (prevNode == -1)         // -1 if no path is found
        {
            printf("\t\tPath does not exist.");
            return 0;
        }
        path[length] = prevNode;
        length++;
        prevNode = shortest[prevNode];
    }


    printf("\t\t\t%d -> ", from + 1);     // print the path from source to destination
    for (int i = length - 1; i > 0; i--)
    {
        printf("%d -> ", path[i] + 1);
    }
    printf("%d", to + 1);

}

void shortestPath(int v, int cost[VERTICES][VERTICES], int dist[], int shortest[], int n)
{

    int status[6];

    for (int i = 0; i < n; i++)    // initializing vectors
    {
        status[i] = 0;
        dist[i] = cost[v][i];
        shortest[i] = dist[i] == 999 ? -1 : 0;
    }

    status[v] = 1;
    dist[v] = 0;
    shortest[v] = v;

    for (int i = 2; i < n - 1; i++)
    {
        int u = findNearestUnvisitedVertex(dist, status, n);
        status[u] = 1;

        for (int w = 0; w < n; w++)                     // check if we can get to w from u in a shorter path
        {
            if (cost[u][w] != 999)
            {
                if (dist[w] > dist[u] + cost[u][w])
                {
                    dist[w] = dist[u] + cost[u][w];
                    shortest[w] = u;
                }
            }
        }
    }
}

int findNearestUnvisitedVertex(int dist[], int status[], int n)
{
    int u = -1;
    for (int i = 0; i < n; i++)
    {
        if (!status[i])
        {
            if (u == -1 || dist[u] > dist[i]) u = i;
        }
    }
    return u;
}
