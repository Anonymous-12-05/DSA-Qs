//https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h> 
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int>dp1(n,1),dp2(n,1);

    for(int i=0;i<n;i++){
        for(int pi=0;pi<i;pi++){
            if(arr[pi]<arr[i] && dp1[i]<dp1[pi]+1){
                dp1[i]=1+dp1[pi];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int pi=n-1;pi>i;pi--){
            if(arr[pi]<arr[i] && dp2[i]<dp2[pi]+1){
                dp2[i]=1+dp2[pi];
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;

} 
