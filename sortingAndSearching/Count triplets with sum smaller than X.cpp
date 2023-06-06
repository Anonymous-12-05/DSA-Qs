//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
        // vector<vector<long long>> sol;
        // sort(arr,arr+n);
	    // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if((arr[i]+arr[j]+arr[k])<sum){
        //                 sol.push_back({arr[i],arr[j],arr[k]});
        //             }
        //         }
        //     }
        // }
        // int count=0;
        // for(int i=0;i<sol.size();i++){
        //     count++;
        // } 
        // return count;   // Your code goes here
        int c=0;
        sort(arr,arr+n);
        for(int k=0;k<n-2;k++){
            int i=k+1;
            int j=n-1;
            while(i<j){
                int s=arr[i]+arr[j]+arr[k];
                if(s<sum){
                    c+=(j-i);
                    i++;

                }
                else{
                    j--;
                }
            }
        }
        return c;
    }
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends