//https://leetcode.com/problems/palindrome-partitioning-ii/
#include<bits/stdc++.h>
using namespace std;
bool isPallindrome(string temp){
    int i=0,j=temp.size()-1;
    while(i<j){
        if(temp[i]!=temp[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int f(int i,string &s,vector<int>&dp){
    int n=s.size();
    int mincost=INT_MAX;
    if(dp[i]!=-1){return dp[i];}
    if(i==n)return 0;
    string temp="";
    for(int j=i;j<n;j++){
        temp+=s[j];
        if(isPallindrome(temp)){
            int cost=1+f(j+1,s,dp);
            mincost=min(mincost,cost);
        }
    }
    return dp[i]= mincost;

}
int minCut(string s) {
    vector<int>dp(s.size()+1,-1);
    return f(0,s,dp)-1;
}
bool check(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCutTab(string s) {
        vector<int>dp(s.size()+1, 0);
        for(int i=s.size()-1; i>=0; i--){
            int ans=INT_MAX;
            for(int j=i; j<s.size(); j++){
                if(check(i, j, s)){
                    int cnt=1+dp[j+1];
                    ans=min(ans, cnt);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }

