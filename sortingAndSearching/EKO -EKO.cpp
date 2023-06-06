//https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
using namespace std;
// #define long long int
bool CuttingPossible(long long int arr[],long long int n,long long int m,long long int height){
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        if(arr[i]>height){
            sum+=(arr[i]-height);
        }
        else{continue;}
    }
    if(sum>=m){
        return true;
    }
    return false;
}
long long int main(){
    long long int n,m;
    cin>>n>>m;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int low=*min_element(arr,arr+n),high=*max_element(arr,arr+n),ans=-1;
    while(low<=high){
        long long int mid=(low+high)/2;
        if(CuttingPossible(arr,n,m,mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}