//{ Driver Code Starts
/* Driver program to test above function */
//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int minimum(int A[],int n){
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(min>A[i]){
                min=A[i];
            }
        }
        return min;

    }
    int maximum(int A[],int n){
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<A[i]){
                max=A[i];
            }
        }
        return max;

    }
    int findSum(int A[], int N)
    {
    	return maximum(A,N)+minimum(A,N);//code here.
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends