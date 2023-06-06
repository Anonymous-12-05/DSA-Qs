//https://leetcode.com/problems/search-in-rotated-sorted-array/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int x) {
        // int k=0;
        // for(int i=1;i<arr.size();i++){
        //     if(arr[i-1]>arr[i]){
        //     k=i;
        //     }
        // }
        // cout<<k<<' ';
        // sort(arr.begin(),arr.end());
        // //int ans;
        // int l=0,h=arr.size()-1;
        // while(l<=h){
        //     int mid=(l+h)/2;
        //     if(arr[mid]<x){
        //     l=mid+1;
        //     }
        //     else if(arr[mid]>x){
        //         h=mid-1;
        //     }
        //     else{
        //         return mid+k;
        
        //     }
        
        // }
        // return -1;
        // int k=-1;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==x){
        //         k=i;
        //     }
        // }
        // return k;
        int l=0,r=arr.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                return mid;
            }
            //left sorted array
            if(arr[l]<=arr[mid]){
                if (x>arr[mid] or x<arr[l]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            //right sorted array
            else{
                if(x<arr[mid] or x>arr[r]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
int main(){
    vector<int>arr={3,1};
    cout<<search(arr,3)<<endl;
}