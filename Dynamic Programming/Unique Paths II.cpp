//https://leetcode.com/problems/unique-paths-ii/
#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
    if(i>=0 && j>=0 &&obstacleGrid[i][j]==1){return 0;}
    if(i==0 && j==0){
        return 1;

    }
    if(i<0 || j<0 ){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int up,left;
    
    up=f(i-1,j,obstacleGrid,dp);
    
    left=f(i,j-1,obstacleGrid,dp);
    
    return dp[i][j]=left+up;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
}
int uniquePathsWithObstaclesTabulation(vector<vector<int>>& obstacleGrid) {
    
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){dp[0][0]=1;}
            else if(i>=0 && j>=0 && obstacleGrid[i][j]==1 ){dp[i][j]=0;}
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
}