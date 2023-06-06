//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long maxi=LONG_MIN,sum=0;
        long long start=-1;
        long long anss=-1,anse=-1;
        for(long long i=0;i<n;i++){
            if(sum==0){start=i;}
            sum=sum+arr[i];
            if(sum>maxi){
                maxi=sum;
                anss=start;
                anse=i;
            }
            if(sum<0){
                sum=0;
            }
        }// Your code here
        //for(int i=anss;i<=anse;i++){
         //   cout<<arr[i]<<" ";
        //}
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends