//https://leetcode.com/problems/is-graph-bipartite/
#include <bits/stdc++.h>
using namespace std;
    bool check(int start, int V, vector<vector<int>> adj, int color[]) {
        queue<int> q;
	    q.push(start); 
	    color[start] = 0; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        
	        for(auto it : adj[node]) {
	            // if the adjacent node is yet not colored
	            // you will give the opposite color of the node 
	            if(color[it] == -1) {
	                
	                color[it] = !color[node]; 
	                q.push(it); 
	            }
	            // is the adjacent guy having the same color 
	            // someone did color it on some other path 
	            else if(color[it] == color[node]) {
	                return false; 
	            }
	        }
	    }
	    return true; 
    }

	bool isBipartiteBFS( vector<vector<int>> adj){
	    int V=adj.size();
        int color[V]; 
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    for(int i = 0;i<V;i++) {
	        // if not coloured
	        if(color[i] == -1) {
	            if(check(i, V, adj, color) == false) {
	                return false; 
	            }
	        }
	    }
	    return true; 
	}

 

    bool dfs(int node, int col, int color[], vector<vector<int>> adj) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }

	bool isBipartiteDFS(vector<vector<int>>adj){
	    int V=adj.size();
        int color[V];
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) 
	                return false; 
	        }
	    }
	    return true; 
	}

