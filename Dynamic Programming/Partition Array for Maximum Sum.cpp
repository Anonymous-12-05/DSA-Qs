//https://leetcode.com/problems/partition-array-for-maximum-sum/
#include<bits/stdc++.h>
using namespace std;
int f(int i,vector<int>& arr, int k,vector<int>&dp){
    int n=arr.size();
    if(i==n) return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MIN,len=0,maxelem=INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxelem=max(maxelem,arr[j]);
        int sum=len*maxelem+f(j+1,arr,k,dp);
        ans=max(sum,ans);
    }
    return dp[i]= ans;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int>dp(arr.size(),-1);
    return f(0,arr,k,dp);    
}