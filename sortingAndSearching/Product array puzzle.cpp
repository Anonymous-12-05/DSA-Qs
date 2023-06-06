//{ Driver Code Starts
//Initial template for C++
//https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
        // vector<long long>ans;
        // long long prod=1;
        // for(int i=0;i<n;i++){
        //     // int prod=1;
        //     prod*=arr[i];
        //     //ans.push_back(prod);

        // }
        // // ans.push_back(prod);
        // for(int i=0;i<n;i++){
        //     ans.push_back(prod/arr[i]);
        // }
        // return ans;
        //code here   
        vector<long long int >l(n),r(n);
        l[0]=1;
        r[n-1]=1;
        for(int i=1;i<n;i++){
            l[i]=l[i-1]*arr[i-1];
        }     
        for(int i=n-2;i>=0;i--){
            r[i]=r[i+1]*arr[i+1];
        }
        for(int i=0;i<n;i++){
            arr[i]=l[i]*r[i];
        }
        return arr;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends