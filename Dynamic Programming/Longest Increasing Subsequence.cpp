//https://leetcode.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;
int f(int ind,int prev_ind,vector<int>&nums, vector<vector<int>>&dp){
    int n=nums.size();
     if(ind == n)
        return 0;
        
    if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];
    
    int notTake = 0 + f(ind+1,prev_ind,nums,dp);
    
    int take = 0;
    
    if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
        take = 1 + f(ind+1,ind,nums,dp);
    }
    
    return dp[ind][prev_ind+1] = max(notTake,take);


}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(0,-1,nums,dp); 
}