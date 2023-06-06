//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
int binsearch(int arr[],int n,int x){
    int l=0,h=n-1;
    int res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]<x){
            l=mid+1;
        }
        else if(arr[mid]>x){
            h=mid-1;
        }
        else{
            res=mid;
            h=mid-1;
        }
    }
    return res;
}
int binsearchlast(int arr[],int n,int x){
    int l=0,h=n-1;
    int res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]<x){
            l=mid+1;
        }
        else if(arr[mid]>x){
            h=mid-1;
        }
        else{
            res=mid;
            l=mid+1;
        }
    }
    return res;
}
vector<int> find(int arr[], int n , int x )
{
    int i=binsearch(arr,n,x);
    vector<int> sol;
    sol.push_back(i);
    int j=binsearchlast(arr,n,x);
    sol.push_back(j);
    return sol;
    

}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends