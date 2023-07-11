//https://leetcode.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;
int f(int ind,int amount,vector<int>& coins, vector<vector<int>>&dp){
    if(ind==0){
       if(amount%coins[ind]==0){
           return amount/coins[ind];
       }
       return 1e9;
    }
    if(amount==0){return 0;}
    if(dp[ind][amount]!=-1){return dp[ind][amount];}
    int notPick=0+f(ind-1,amount,coins,dp);
    int pick=1e9;
    if(amount>=coins[ind]){
        pick=1+f(ind,amount-coins[ind],coins,dp);
    }
    return dp[ind][amount]=min(pick,notPick);
}
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
}


int coinChangeTab(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}