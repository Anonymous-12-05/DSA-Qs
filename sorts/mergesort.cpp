#include <bits/stdc++.h>
using namespace std;
void Merge(int arr[],int l,int mid,int h){
    int i=l,k=l,j=mid+1;
    int b[100];
    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++]=arr[i];
    }
    for(;j<=h;j++){
        b[k++]=arr[j];
    }
    for(i=l;i<=h;i++){
        arr[i]=b[i];
    }
}
void ImergeSort(int arr[],int n){
    int p,l,mid,h,i;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(arr,l,mid,h);
        }
    }
    if(p/2<n){
        Merge(arr,0,p/2-1,n);
    }
}
void RmergeSort(int arr[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        RmergeSort(arr,l,mid);
        RmergeSort(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}
int main(){
    int arr[10]={8,6,7,7,8,4,12,5,7,7};
    RmergeSort(arr,0,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}