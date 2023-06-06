//https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;
int canPlaceCows(int arr[],int n,int c,int dist){
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        int arr[n];
        cin>>n>>c;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // vector<int >mindist;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             int d1=abs(arr[i]-arr[j]);
        //             int d2=abs(arr[j]-arr[k]);
        //             mindist.push_back(min(d1,d2));
        //         }
        //     }
        // }
        // cout<<*max_element(mindist.begin(),mindist.end());
        int low=1,high=arr[n-1]-arr[0],res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            cout<<canPlaceCows(arr,n,c,mid)<<endl;
            if(canPlaceCows(arr,n,c,mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<res<<endl;
    }
}