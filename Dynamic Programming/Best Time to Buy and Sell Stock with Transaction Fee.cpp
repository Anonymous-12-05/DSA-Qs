//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include<bits/stdc++.h>
using namespace std;
int f(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp,int fee){
    if(ind==prices.size())return 0;
    int profit;
    if(dp[ind][buy]!=-1){return dp[ind][buy];}
    if(buy){
        profit=max(-1*prices[ind]+f(ind+1,0,prices,dp,fee),f(ind+1,1,prices,dp,fee));
    }
    else{
         profit=max(prices[ind]-fee+f(ind+1,1,prices,dp,fee),f(ind+1,0,prices,dp,fee));
    }
    return dp[ind][buy]=profit;
}

int maxProfit(vector<int>& prices, int fee) {
    int buy=1;
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    return f(0,buy,prices,dp,fee);   
}