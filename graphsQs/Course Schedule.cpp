//https://leetcode.com/problems/course-schedule/
#include<bits/stdc++.h>
using namespace std;
 bool dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 2;
        for (auto it: adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis) == true)
                    return true;
            } else if (vis[it] == 2) {
                return true;
            }
        }
        vis[node] = 1;
        return false;  
    }
    bool canFinishDFS(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector <int> vis(numCourses, 0);
        vector <int> adj[numCourses];
        for (int i = 0; i < n; i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis) == true)
                    return false;
            }
        }
        return true;
    }

bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector <int> indegree(numCourses, 0);
        vector <int> adj[numCourses];
        for (int i = 0; i < n; i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; i++) 
            for (auto it: adj[i]) 
                indegree[it]++;
        queue <int> q;        
        for (int i = 0; i < numCourses; i++) 
            if (indegree[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (cnt == numCourses)
            return true;
        return false;
    }