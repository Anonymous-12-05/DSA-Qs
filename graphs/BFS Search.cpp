#include <bits/stdc++.h>
//#include <queue>

using namespace std;
 
void BFS(int vtx, int A[][8], int n){
    queue<int> Q;
    int visited[8] {0};
 
    // Initial
    cout << vtx << ", " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.emplace(vtx);
 
    // Explore
    while (!Q.empty()){
        int u = Q.front();  // Vertex u for exploring
        Q.pop();
        for (int v=1; v<=n; v++){  // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0){  // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}
void RDFS(int u, int A[][8], int n){
    static int visited[8] {0};
 
    if (visited[u] == 0){
        cout << u << ", " << flush;
        visited[u] = 1;
        for (int v=1; v<n; v++){
            if (A[u][v] == 1 && visited[v] == 0){
                DFS(v, A, n);
            }
        }
    }
}
void DFS(int u, int A[][8], int n) {
    // Initialize visit tracking array and stack
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    // Visit start vertex u
    cout << u << ", " << flush;
    visited[u] = 1;  // Visited vertex u
 
    // Initial Adjacent vertex
    int v = 0;
 
    while (!stk.empty()){
        while (v < n){
            if (A[u][v] == 1 && visited[v] == 0){
                stk.push(u); // Suspend exploring current vertex u
                u = v;  // Update current vertex as the next adjacent vertex
 
                // Visit current vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                v = -1;  // Increment will make this 0
            }
            v++;
        }
        v = u;  // Can set v = 0 but setting v = u is better
        u = stk.top();  // Return to previous suspended vertex
        stk.pop();
    }
}
 
// Simpler and adds elements to stack from end
void dfs(int u, int A[][8], int n){
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    while (!stk.empty()){
        u = stk.top();
        stk.pop();
 
        if (visited[u] != 1){
            cout << u << ", " << flush;
            visited[u] = 1;
 
            for (int v=n-1; v>=0; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    stk.emplace(v);
                }
            }
        }
    }
}
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
 
 
    return 0;
}