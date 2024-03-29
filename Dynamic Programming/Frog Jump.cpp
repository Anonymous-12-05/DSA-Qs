//https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h> 
using namespace std;
int f(int ind,vector<int>&heights,vector<int>&dp){
    
    if(ind==0){return 0;}
    if(dp[ind]!=-1){return dp[ind];}
    int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1){
        right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(left,right);

}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
    // Write your code here.
}
int frogJumpSpaceoptimised(int n, vector<int> &heights)
{
    int prev=0,prev2=0;
    for(int i=1;i<n;i++){
        int first=prev+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=prev2+abs(heights[i]-heights[i-2]);
        }
        int curr=min(first,ss);
        prev2=prev;
        prev=curr;
    }
    return prev;
}