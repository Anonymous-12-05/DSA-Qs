#include<bits/stdc++.h>
using namespace std;
// bool isConnectable(const string& s1, const string& s2) {
//     return s1.back() == s2.front();
// }

// void generatePermutations(vector<string>& strs, vector<string>& permutations, vector<bool>& visited, string current_chain) {
//     if (current_chain.size() == strs.size() * 2) {
//         permutations.push_back(current_chain);
//         return;
//     }

//     for (int i = 0; i < strs.size(); ++i) {
//         if (!visited[i]) {
//             if (current_chain.empty() || isConnectable(current_chain, strs[i])) {
//                 visited[i] = true;
//                 generatePermutations(strs, permutations, visited, current_chain + strs[i]);
//                 visited[i] = false;
//             }
//         }
//     }
// }

// string solution(vector<string>& A) {
//     vector<string> permutations;
//     vector<bool> visited(A.size(), false);
//     generatePermutations(A, permutations, visited, A[0]);

//     string result;
//     for (const string& perm : permutations) {
//         bool can_connect = true;
//         for (int i = 0; i < A.size() - 1; ++i) {
//             if (!isConnectable(perm.substr(i * 2, 2), perm.substr((i + 1) * 2, 2))) {
//                 can_connect = false;
//                 break;
//             }
//         }
//         result += can_connect ? '1' : '0';
//     }

//     return result;
// }
// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>

// using namespace std;

// struct Node {
//     char value;
//     Node* next;
//     Node(char val) : value(val), next(nullptr) {}
// };

// struct Graph {
//     Node* first;
//     Node* last;
//     Graph() : first(nullptr), last(nullptr) {}
// };

// Node* createNode(char value) {
//     return new Node(value);
// }

// void addEdge(Graph& graph, char start, char end) {
//     Node* startNode = createNode(start);
//     Node* endNode = createNode(end);

//     if (graph.first == nullptr) {
//         graph.first = startNode;
//         graph.last = endNode;
//     } else {
//         graph.last->next = startNode;
//         graph.last = endNode;
//     }
// }

// bool dfsWithMemoization(Node* currentNode, char target, vector<bool>& visited, vector<vector<bool>>& memo) {
//     if (currentNode->value == target) {
//         return true;
//     }

//     if (visited[currentNode->value - 'a']) {
//         return false;
//     }

//     visited[currentNode->value - 'a'] = true;

//     Node* neighbor = currentNode->next;
//     while (neighbor != nullptr) {
//         if (dfsWithMemoization(neighbor, target, visited, memo)) {
//             memo[currentNode->value - 'a'][target - 'a'] = true;
//             memo[target - 'a'][currentNode->value - 'a'] = true; // Update the opposite direction in the memo array
//             return true;
//         }
//         neighbor = neighbor->next;
//     }

//     return false;
// }

// string solution(vector<string> A, int N) {
//     string result;
//     Graph graph;

//     // Create the graph representation of the strings
//     for (int i = 0; i < N; i++) {
//         addEdge(graph, A[i][0], A[i][1]);
//     }

//     // Initialize memoization array
//     vector<vector<bool>> memo(26, vector<bool>(26, false));

//     // Check for connectivity for each K
//     for (int K = 0; K < N; K++) {
//         result += '0';

//         // Perform DFS with memoization
//         vector<bool> visited(26, false);
//         for (int i = 0; i < 26; i++) {
//             if (dfsWithMemoization(graph.first, A[K][1], visited, memo)) {
//                 result[K] = '1';
//                 break; // If the current string chain can be connected, move to the next K.
//             }
//             visited.assign(26, false); // Reset visited array for each DFS call
//         }
//     }

//     return result;
// }
// char first(string s){
//     return s[0];
// }
// char last(string s){
//     return s[1];
// }
// string soln(vector<string>A,int N){
//     string s="1";
//     for(int i=1;i<N;i++){
//         s+='0';
//     }
//     for(int i=0;i<N;i++){
//         for(int j=0;j<i;j++){
//             if(last(A[i])==first(A[j])){
//                 s[i]='1';
//             }

//         }
//     }
//     return s;
// }

// int main() {
//     vector<string> A = {"he", "ll", "lo","el"};
//     int N = A.size();
//     string result = soln(A, N);
//     cout << result << endl; // Output: "1001"

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

bool canConnect(const string& s1, const string& s2) {
    return s1[1] == s2[0];
}

string solution(vector<string>& A) {
    int N = A.size();
    string result(N, '0');  // Initialize result string with '0'

    // Base case: First string can always be connected
    result[0] = '1';

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (canConnect(A[j], A[i]) && result[j] == '1') {
                // If A[j] can be connected and A[0] to A[j] can be connected, then A[0] to A[i] can also be connected
                result[i] = '1';
                break;
            }
        }
    }

    return result;
}

int main() {
    vector<string> A = {"he", "ll", "lo", "el"};
    string result = solution(A);

    cout << result << endl;  // Output: "1110"

    return 0;
}
