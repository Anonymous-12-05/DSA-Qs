//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    private:
    void dfs(int start, vector<vector<int>>& adj, vector<int>&vis, stack<int>&st,int v){
        vis[start]=1;
        
        for(auto it: adj[start]){
            if(!vis[it])
            dfs(it,adj,vis,st,v);
        }
        
        st.push(start);
    }
    
    
    void dfsnew(int start,vector<int> adj[], vector<int>&vis){
        vis[start]=1;
        for(auto it: adj[start]){
            if(!vis[it])
            dfsnew(it,adj,vis);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //step1
        //storing elemets according to finishing time
        vector<int> vis(V,0);
        stack<int>st;
        
        for(int i=-0; i<V; i++){
            if(!vis[i])
            dfs(i,adj,vis,st,V);
        }
        
        //step2
        //reverseing the graph
        vector<int> adjReverse[V];
        for(int i=0; i<V; i++){
            vis[i]=0;// reseting the vis arr so that we can use it again for next step
            for(auto it: adj[i]){
                adjReverse[it].push_back(i);
            }
        }
        
        
        //step3
        //again calling the dfs to count ssc
        int ssc=0;
        
        while(!st.empty()){
            int it= st.top();
            st.pop();
            
            if(!vis[it])
            {
                ssc++;    
                dfsnew(it,adjReverse,vis);
            }
            
        }
        
        return ssc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends