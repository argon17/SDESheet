#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; ++i){
            if(vis[i]==0 && !dfs(i, 1, vis, graph)) return 0;
        }
        return 1;
    }
    
    bool dfs(int node, int group, vector<int> &vis, vector<vector<int>> graph){
        vis[node] = group;
        for(auto it:graph[node]){
            if(vis[it]==group) return 0;
            if(vis[it]==0 && !dfs(it, -group, vis, graph)) return 0;
        }
        return 1;
    }
};

// another LC problem
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(auto it:dislikes){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int> vis(n, 0);
        // 0->uncolored, 1->1st group, -1->2nd group
        for(int i=0; i<n; ++i){
            // if uncolored, then try to color adj, if couldn't, return false
            if(vis[i]==0 && !dfs(i, 1, vis, adj)) return 0;
        }
        return 1;
    }
    
    bool dfs(int node, int group, vector<int> &vis, vector<int> adj[]){
        vis[node] = group;
        for(auto it: adj[node]){
            // if adj has same color, can't color
            if(vis[it]==group) return 0;
            // if still uncolored, then try to color adj, if couldn't, return false
            if(vis[it]==0 && !dfs(it, -group, vis, adj)) return 0;
        }
        // no problem occured, return true
        return 1;
    }
};