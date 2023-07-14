//https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_624880?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
using namespace std;

int f(int l,int r,int* arr,vector <vector <int>> &dp){
    if(r-l<=1) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int ans = 1e9;
    for(int p = l+1;p < r;p++){
        int tmp = f(l,p,arr,dp) + f(p,r,arr,dp) + arr[l]*arr[p]*arr[r];
        ans = min(ans,tmp);
    }
    return dp[l][r] =  ans;
}


int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector <vector <int>> dp(n+1,vector <int>(n+1,-1));
    return f(0,n,arr,dp); 
}

int matrixChainMultiplication(int* arr, int n) {
    int dp[n+1][n+1];
    for(int i=1;i<=n;i++)dp[i][i]=0;

    for(int i=n;i>=1;i--){
        for(int j=i+1;j<n+1;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n];
}