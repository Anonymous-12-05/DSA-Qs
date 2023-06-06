//https://www.spoj.com/problems/PRATA/
#include <bits/stdc++.h>
using namespace std;
bool cansolve(int arr[],int n,int p,int mid){
    int time=0;
    int paratha=0;
    for(int i=0;i<n;i++){
        time=arr[i];
        int j=2;
        while(time<=mid){
            paratha++;
            time+=(arr[i]*j);
            j++;
        }
        if(paratha>=p){
            return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int p,n;
        cin>>p>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int low=0,high=1e8,ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(cansolve(arr,n,p,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    // cout<<ans<<endl;
}