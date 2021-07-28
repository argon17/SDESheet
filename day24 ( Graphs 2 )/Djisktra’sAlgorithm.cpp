#include <bits/stdc++.h>
using namespace std;

// Dijkstra on Graph

const int INF = 2147483647;
const int MAX = 5005;
int dist[MAX], N;                // Keeps minimum distance to each node
vector<pair<int, int>> adj[MAX]; // Adjacency list

void dijkstra()
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    // {dist, node}
    priority_queue<pair<int, int>> q;
    q.push({dist[1] = 0, 1});

    while (!q.empty())
    {
        pair<int, int> cur = q.top();
        q.pop();

        int curNode = cur.second, curDist = -cur.first;
        if (curDist > dist[curNode]) continue;

        // {node, weight}
        for (pair<int, int> neighbor : adj[curNode])
        {
            int nextNode = neighbor.first;
            int nextDist = curDist + neighbor.second;

            if (nextDist > dist[nextNode]) continue;
            dist[nextNode] = nextDist;
            q.push({-nextDist, nextNode});
        }
    }
}

// Dijkstra on grid

const int row = 5, col = 5;

bool inside(int r, int c)
{
    return r >= 0 && r < row && c >= 0 && c < col;
}

int dijkstra(int grid[row][col])
{
    int dist[row][col];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            dist[i][j] = INT_MAX;
        }
    }
    // {dist, node}
    priority_queue<pair<int, int>> q;
    dist[0][0] = grid[0][0];
    q.push({-grid[0][0], 0});
    while (q.size())
    {
        auto cur = q.top();
        q.pop();
        int curNode = cur.second;
        int curNodeX = cur.second / col, curNodeY = cur.second % col;
        int curDist = -cur.first;
        if (curDist > dist[curNodeX][curNodeY]) continue;
        int dirs[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; ++i)
        {
            int nextNodeX = curNodeX + dirs[i];
            int nextNodeY = curNodeY + dirs[i + 1];
            if (1 ^ inside(nextNodeX, nextNodeY)) continue;
            int nextDist = curDist + grid[nextNodeX][nextNodeY];
            if (nextDist > dist[nextNodeX][nextNodeY]) continue;
            dist[nextNodeX][nextNodeY] = nextDist;
            q.push({-nextDist, nextNodeX * col + nextNodeY});
        }
    }
    return dist[row - 1][col - 1];
}
