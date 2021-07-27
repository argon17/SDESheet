#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int V, int cur)
{
    for (int i = 0; i < V; ++i)
    {
        if (i != node && graph[i][node] == 1 && color[i] == cur)
            return 0;
    }
    return 1;
}

bool ok(int node, int color[], int m, int V, bool graph[101][101])
{
    if (node == V)
        return 1;

    // else try every possibility
    for (int i = 1; i <= m; ++i)
    {
        if (isSafe(node, color, graph, V, i))
        {
            color[node] = i;
            if (ok(node + 1, color, m, V, graph))
                return 1;
            color[node] = 0;
        }
    }
    return 0;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your c
    int color[V] = {0};
    if (ok(0, color, m, V, graph))
        return 1;
    return 0;
}