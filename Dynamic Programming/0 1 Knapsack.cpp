//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
using namespace std;
int f(int ind,int W,vector<int> &weight, vector<int> &value, vector<vector<int>>&dp){
    if(ind==0){
        if(weight[ind]<=W){return value[0];}
        else{
            return 0;

        }
    }
    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }
    int notTake=0+f(ind-1,W,weight,value,dp);
    int take=INT_MIN;
    if(weight[ind]<=W){
        take=value[ind]+f(ind-1,W-weight[ind],weight,value,dp);
    }

    return dp[ind][W]= max(notTake,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(weight.size(),vector<int>(maxWeight+1,-1));
	return f(weight.size()-1,maxWeight,weight,value,dp);
    // Write your code here
}

int knapsackTab(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}