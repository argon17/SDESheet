#include <bits/stdc++.h>
using namespace std;

class Solution
{
	void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st){
	    if(vis[node]) return;
	    vis[node] = 1;
	    for(auto nbr : adj[node])
	        dfs(nbr, adj, vis, st);
	   st.push(node);
	}
	
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V, 0);
	    stack<int> st;
	    for(int i=0; i<V; ++i)
	        if(!vis[i]) dfs(i, adj, vis, st);
	    vector<int> ans;
	    while(st.size()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
