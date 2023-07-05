//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int node,vector<int>adj[],int vis[],vector<int>&ans){
        queue<int>q;
        ans.push_back(node);
        vis[node]=1;
        q.push(node);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto it:adj[u]){
                if(!vis[it]){
                    ans.push_back(it);
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int visited[V]={0};
        int start=0;
        vector<int>ans;
        bfs(start,adj,visited,ans);
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends