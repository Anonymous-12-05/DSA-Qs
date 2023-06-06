//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge1(long long int a[],long long int temp[],long long int left,long long int mid,long long int right){
        long long int i,j,k,inv=0;
        i=left;
        j=mid;
        k=left;
        while((i<=mid-1)&& (j<=right)){
            if(a[i]<=a[j]){
                temp[k++]=a[i++];
            }
            else{
                temp[k++]=a[j++];
                inv+=(mid-i);
            }
        }
        while(i<=mid-1){
            temp[k++]=a[i++];
        }
        while(j<=right){
            temp[k++]=a[j++];
        }
        for(int m=left;m<=right;m++){
            a[m]=temp[m];
        }
        return inv;
    }
    long long int mergesort(long long int a[],long long int temp[],long long int left,long long int right){
        long long int inv=0;
        if(left<right){
            long long int mid=(left+right)/2;
            inv+=mergesort(a,temp,left,mid);
            inv+=mergesort(a,temp,mid+1,right);
            inv+=merge1(a,temp,left,mid+1,right);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int temp[N];
        long long int inv=mergesort(arr,temp,0,N-1);
        return inv;
        // Your Code Here
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends