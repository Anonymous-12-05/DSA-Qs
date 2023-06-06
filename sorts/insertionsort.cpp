#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int x=arr[i];
        while(j>-1 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main(){
    int arr[7]={6,8,12,14,18,20,2};
    insertionSort(arr,7);
    for(int i=0;i<7 ;i++){
        cout<<arr[i]<<" ";
    }
}