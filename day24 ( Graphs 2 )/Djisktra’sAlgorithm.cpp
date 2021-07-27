#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;
const int MAX = 5005;
int dist[MAX], N;                // Keeps minimum distance to each node
vector<pair<int, int>> adj[MAX]; // Adjacency list

void dijkstra()
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>> q;
    q.push({dist[1] = 0, 1});

    while (!q.empty())
    {
        pair<int, int> cur = q.top();
        q.pop();

        int curNode = cur.second, curDist = -cur.first;
        if (curDist > dist[curNode]) continue;

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