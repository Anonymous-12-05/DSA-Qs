#include<bits/stdc++.h>
using namespace std;
void reverse(int  arr[],int n){
    int i;
    int j;
    for( i=0, j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}