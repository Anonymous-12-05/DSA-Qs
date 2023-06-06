#include <bits/stdc++.h>
using namespace std;
void countsort(int arr[],int n){
    int max=*max_element(arr,arr+n);
    int *C;
    C=new int[max+1];
    for(int i=0;i<max+1;i++){
        C[i]=0;
    }
    for(int j=0;j<n;j++){
        C[arr[j]]++;
    }
    int i=0,j=0;
    while(i<max+1){
        if(C[i]>0){
            arr[j++]=i;
            C[i]--;
        }
        else{
            i++;
        }
    }
}
int main(){
    int n=10;
    int arr[n]={6,3,9,10,15,6,8,12,3,6};
    countsort(arr,n);
    for(int j=0;j<n;j++){
        cout<<arr[j]<<' ';
    }
}