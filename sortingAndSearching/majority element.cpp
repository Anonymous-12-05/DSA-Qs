//{ Driver Code Starts
//Initial template for C++
//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int maxim=*max_element(a,a+size);
        //cout<<maxim<<" "<<endl;
        int H[maxim+1]={0};
        for(int i=0;i<size;i++){
            H[a[i]]++;
        }
        for(int i=0;i<maxim+1;i++){
            if(H[i]>(size/2)){
                return i;
            }
        }
        // for(int i=0;i<maxim+1;i++){
        //     cout<<H[i]<<" ";
        // }
        return -1;
        // your code here
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends