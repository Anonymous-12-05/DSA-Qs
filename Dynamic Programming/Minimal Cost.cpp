//https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
using namespace std;
int energy(int n,int k,vector<int>&height,vector<int>&dp){
    if(n==0){return 0;}

    int minim=INT_MAX;
    if(dp[n]!=-1){return dp[n];}
    for(int i=1;i<=k;i++){
        if(n-i>=0){
        int mjump=energy(n-i,k,height,dp)+abs(height[n]-height[n-i]);
        minim=min(minim,mjump);
        }
    }
    return dp[n]= minim;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int>dp(n+1,-1);
    return energy(n-1,k,height,dp);

}