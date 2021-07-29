#include <bits/stdc++.h>
using namespace std;

// Dijkstra on Graph

const int INF = 2147483647;
const int MAX = 5005;
int dist[MAX], N;          // Keeps minimum distance to each node
vector<vector<int>> edges; // Directed Edges

// O(VE) TC
void bellmanFord()
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[0] = 0;
    // n-1 times edges relaxation
    for (int i = 0; i < N - 1; ++i)
    {
        // relax each edge
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
}
