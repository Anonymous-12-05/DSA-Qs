//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
    int solve(int start_stick, int end_stick, vector<int>& cuts, int left, int right){
        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int cost = 1e9;
        
        for(int i=left; i<=right; i++){
            int left_cost = solve(start_stick, cuts[i], cuts, left, i-1);
            int right_cost = solve(cuts[i], end_stick, cuts, i+1, right);
            int curr_cost = (end_stick - start_stick) + left_cost + right_cost;
            cost = min(cost,curr_cost);
        }
        
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return solve(0, n, cuts, 0, cuts.size()-1);
    }
        int minCostTab(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(begin(cuts), 0);
        sort(begin(cuts), end(cuts));
        
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
        
        for(int i=c; i>0; i--){
            for(int j=1; j<=c; j++){
                if(i>j) continue;
                
                int res = INT_MAX;
        
                for(int idx=i; idx<=j; idx++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1]
                        + dp[idx+1][j];

                    res = min(res, cost);
                }

                dp[i][j] = res;
            }
        }
        
        return dp[1][c];
    }
