//{ Driver Code Starts
// Initial template for C++
//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool AllocatedBook(int A[],int n,int M,int barrier){
        int allocatedstud=1,pages=0;
        for(int i=0;i<n;i++){
            if(A[i]>barrier){return false;}
            if(pages+A[i]>barrier){
                allocatedstud++;
                pages=A[i];
            }
            else{
                pages+=A[i];
            }

        }
        if(allocatedstud>M){
            return false;
        }
        return true;
    }
    int sum(int A[],int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
        }
        return sum;

    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N){return -1;}
        int low=*min_element(A,A+N),high=sum(A,N),res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(AllocatedBook(A,N,M,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;

        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends