//https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int>& arr) {
    int n=arr.size();
    vector<int>dp1(n,1),count(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int pi=0;pi<i;pi++){
            if(arr[pi]<arr[i] && dp1[i]<dp1[pi]+1){
                dp1[i]=1+dp1[pi];
                count[i]=count[pi];
            }
            else if(arr[pi]<arr[i] && dp1[i]==dp1[pi]+1){
                count[i]+=count[pi];
            }
        }
        maxi=max(maxi,dp1[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(dp1[i]==maxi) cnt+=count[i];
    }
    return cnt;
    

}