#include <bits/stdc++.h>
using namespace std;

// DFS Approach

class Solution
{
	void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans){
	    if(vis[node]) return;
	    vis[node] = 1;
	    for(auto nbr : adj[node])
	        dfs(nbr, adj, vis, ans);
	   ans.push_back(node);
	}
	
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V, 0);
	    vector<int> ans;
	    for(int i=0; i<V; ++i)
	        if(!vis[i]) dfs(i, adj, vis, ans);
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

// BFS Approach - Kahn's Algorithm

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indeg(n);
	    for(int i = 0; i < n; ++i)
	        for(int nbr : adj[i]) ++indeg[nbr];
	    queue<int> q;
	    vector<int> ans;
	    for(int i = 0; i < n; ++i)
	        if(indeg[i] == 0) q.push(i);
	    while(q.size()){
	        int cur = q.front();
	        q.pop();
	        ans.push_back(cur);
	        for(int nbr : adj[cur])
	            if(--indeg[nbr] == 0)
	                q.push(nbr);
	    }
	    return ans;
	}
};