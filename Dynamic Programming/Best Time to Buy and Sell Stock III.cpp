//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include<bits/stdc++.h>
using namespace std;
int f(int ind,int buy,int cap,vector<int>& prices, vector<vector<vector<int>>> &dp){
    if(ind==prices.size())return 0;
    if(cap==0)return 0;
    int profit;
    if(dp[ind][buy][cap]!=-1){return dp[ind][buy][cap];}
    if(buy){
        profit=max(-1*prices[ind]+f(ind+1,0,cap,prices,dp),f(ind+1,1,cap,prices,dp));
    }
    else{
         profit=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),f(ind+1,0,cap,prices,dp));
    }
    return dp[ind][buy][cap]=profit;
}
int maxProfit(vector<int>& prices) {
    int buy=1;
    int n=prices.size();
     vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
    return f(0,buy,2,prices,dp); 
}

int maxProfitTab(vector<int>& Arr, int n)
{
        vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,0)));
                                            
  
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -Arr[ind] + dp[ind+1][1][cap]);
                 }
    
                if(buy==1){
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                Arr[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    
    
    return dp[0][0][2];
   
}
int maxProfitSpaceOptimised(vector<int>& Arr, int n)
{
    
    vector<vector<int>> ahead(2,vector<int> (3,0));
    
    vector<vector<int>> cur(2,vector<int> (3,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -Arr[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                Arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][2];
   
}