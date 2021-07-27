#include <bits/stdc++.h>
using namespace std;

// In Graph
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // adjacency matrix
        vector<vector<int>> adj(n);
        int edges = connections.size();
        for(int i=0; i<edges; ++i){
            // store connected vertices in a and b
            int a = connections[i][0];
            int b = connections[i][1];
            // push in adjacency matrix
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int components = 0;
        // initialize visited array
        vector<bool> visited(n, 0);
        for(int v=0; v<n; ++v){
            if(!visited[v]){
                ++components;
                dfs(adj, visited, v);
            }
        }
        // possible only if enough edges(n-1) in the graph
        if(edges>=n-1){
            return components-1;
        }
        return -1;
    }
    void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int node){
        visited[node] = 1;
        for(int adjnode : adj[node]){
            // don't go back
            if(!visited[adjnode])
                dfs(adj, visited, adjnode);
        }
    }
};

// In Grid
// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int row, col;
    int moves[4][2]  = {{-1,0},{1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, (vector<bool>(col, 0)));
        int connected = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ++connected;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return connected;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = 1;
        for(auto move : moves){
            int ni = i+move[0];
            ni = max(0, ni); ni = min(ni, row-1);
            int nj = j+move[1];
            nj = max(0, nj); nj = min(nj, col-1);
            if(!visited[ni][nj] && grid[ni][nj]=='1')
                dfs(grid, visited, ni, nj);
        }
    }
};
