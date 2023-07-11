//https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int findWays(vector<int>& arr, int k)
{
  
    int n = arr.size();

       vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

      dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {

               dp[i][j] = dp[i - 1][j];

               if (arr[i - 1] <= j) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
                dp[i][j] %= MOD;
            }
        }
    }
    return dp[n][k];
}