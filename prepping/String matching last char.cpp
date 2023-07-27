#include<bits/stdc++.h>
using namespace std;
bool isConnectable(const string& s1, const string& s2) {
    return s1.back() == s2.front();
}

void generatePermutations(vector<string>& strs, vector<string>& permutations, vector<bool>& visited, string current_chain) {
    if (current_chain.size() == strs.size() * 2) {
        permutations.push_back(current_chain);
        return;
    }

    for (int i = 0; i < strs.size(); ++i) {
        if (!visited[i]) {
            if (current_chain.empty() || isConnectable(current_chain, strs[i])) {
                visited[i] = true;
                generatePermutations(strs, permutations, visited, current_chain + strs[i]);
                visited[i] = false;
            }
        }
    }
}

string solution(vector<string>& A) {
    vector<string> permutations;
    vector<bool> visited(A.size(), false);
    generatePermutations(A, permutations, visited, A[0]);

    string result;
    for (const string& perm : permutations) {
        bool can_connect = true;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (!isConnectable(perm.substr(i * 2, 2), perm.substr((i + 1) * 2, 2))) {
                can_connect = false;
                break;
            }
        }
        result += can_connect ? '1' : '0';
    }

    return result;
}

int main() {
    vector<string> A = { "he", "ll", "lo", "el" };
    string result = solution(A);
    cout << result << endl;
    return 0;
}
