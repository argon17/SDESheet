#include<bits/stdc++.h>
using namespace std;

// Undirected Graph

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V, 0);
	    for(int i=0; i<V; ++i){
	        if(!vis[i] && dfs(i, -1, vis, adj)) return 1;
	    }
	    return 0;
	}
	
	bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[]){
	    if(vis[node]==1) return 1;
	    vis[node] = 1;
	    for(auto it:adj[node]){
	        if(it!=parent && dfs(it, node, vis, adj)) return 1; 
	    }
	    return 0;
	}
};


// Directed Graph

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> vis(V);
        // 0->unvisited, 1->visited, -1->visiting
	   	for(int i=0; i<V; ++i){
			// cycle is found, return true
	   	    if(vis[i]==0 && dfs(i, vis, adj)) return 1;
	   	}

		// no cycle found return false
	   	return 0;
	}
	
	bool dfs(int node, vector<int> &vis, vector<int> adj[]){
		// it's the node already appeared in current DFS
	    if(vis[node]==-1) return 1;
		// if this is the node of previous DFS, no problem
	    if(vis[node]==1) return 0;
		// currently visiting
	    vis[node] = -1;
		// for all adjacent nodes
	    for(auto it:adj[node]){
			// return true, if cycle is found
	        if(dfs(it, vis, adj)) return 1;
	    }
		// done visiting
	    vis[node] = 1;
		// done dfs, no cycles found
	    return 0;
	}
};


