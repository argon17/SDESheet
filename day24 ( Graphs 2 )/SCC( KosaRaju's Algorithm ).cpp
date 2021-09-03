#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

vector<int> g[mxN], gr[mxN], c(mxN), order, vis(mxN), comps;

void dfs(int u)
{
    vis[u] = 1;
    for (int v : g[u])
        if (!vis[v])
            dfs(v);
    order.push_back(u);
}

void dfsr(int u)
{
    vis[u] = 1;
    for (int v : gr[u])
        if (!vis[v])
            dfsr(v);
    comps.push_back(u);
}

void kosaraju()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);
    vis.assign(mxN, 0);
    reverse(order.begin(), order.end());
    for (int u : order)
    {
        if (!vis[u])
        {
            comps.clear();
            dfsr(u);
            for(int v : comps) cout << v << " ";
        }
    }
}
