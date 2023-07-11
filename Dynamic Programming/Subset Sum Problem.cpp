//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sum-problem-1611555638
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int ind,vector<int>&arr,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0)return arr[0]==target;
        if(dp[ind][target]!=-1){return dp[ind][target];}
        bool notTake=f(ind-1,arr,target,dp);
        bool take=false;
        if(target>=arr[ind]){
            take=f(ind-1,arr,target-arr[ind],dp);
        }

        return dp[ind][target]=take or notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
      
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
        // code here 
    }
    bool isSubsetSumTabulation(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends