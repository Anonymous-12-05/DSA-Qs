//https://leetcode.com/problems/magnetic-force-between-two-balls/
#include <bits/stdc++.h>
using namespace std;
int canPlaceBalls(vector<int>& arr,int n,int c,int dist){
    int coord=arr[0],count=1;
    for(int i=1;i<n;i++){
        if((arr[i]-coord)>=dist){
            count++;
            coord=arr[i];
        }
        if(count==c){
            return 1;
        }
    }
    return 0;
}
    int maxDistance(vector<int>& arr, int c) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int low=1,high=arr[n-1]-arr[0],ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canPlaceBalls(arr,n,c,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }