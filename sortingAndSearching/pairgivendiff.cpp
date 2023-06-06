//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends
int binsearch(int arr[],int n,int x){
    int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]<x){
            l=mid+1;
            }
            else if(arr[mid]>x){
                h=mid-1;
            }
            else{
                return mid;
        
            }

        }
    return -1;
}
bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    //1 2 3 4 6
    if(n==0){
        int maxim=*max_element(arr,arr+size);
        //cout<<maxim<<" "<<endl;
        int H[maxim+1]={0};
        for(int i=0;i<size;i++){
            H[arr[i]]++;
        }
        for(int i=0;i<maxim+1;i++){
            if(H[i]>1){
                return true;
            }
        }
        return false;
    }
    vector<int >sol;
    for(int i=size-1;i>=0;i--){
        if(arr[i]>=n){
            sol.push_back(arr[i]-n);
        }
        else{
            break;
        }
    }
    for(int i=0;i<sol.size();i++){
        if(binsearch(arr,size,sol[i])!=-1){
            return true;
        }
    }
    // for(int i=0;i<sol.size();i++){
    //     cout<<sol[i]<<" ";
    // }
    return false;

    //code
    
}