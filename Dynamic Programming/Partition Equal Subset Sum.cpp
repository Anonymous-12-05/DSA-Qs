//https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;
 bool f(int ind,vector<int>&arr,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0)return arr[0]==target;
        if(dp[ind][target]!=-1){return dp[ind][target];}
        bool notTake=f(ind-1,arr,target,dp);
        bool take=false;
        if(target>=arr[ind]){
            take=f(ind-1,arr,target-arr[ind],dp);
        }

        return dp[ind][target]=take or notTake;
    }

bool canPartition(vector<int>& arr) {
   int sum=0;
   for(int i=0;i<arr.size();i++){
        sum+=arr[i];
   } 
   if(sum%2!=0){return false;}
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
    return f(n-1,arr,sum/2,dp);
}