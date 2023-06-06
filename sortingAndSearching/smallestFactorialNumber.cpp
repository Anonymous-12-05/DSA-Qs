//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool zeroes(int mid,int n){
        int prod=5;int c=0;
        while(prod<=mid){
            c+=(mid/prod);
            prod*=5;
        }
        return c>=n;
    }
        int findNum(int n)
        {
        //no of trailing zeroes is (25/5)+(25/5**2)+25/2**3+....
        if(n==1){
            return 5;
        }
        int lo=0,high=5*n;
        while(lo<high){
            int mid=(lo+high)/2;
            if(zeroes(mid,n)){
                high=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
        //complete the function here
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends