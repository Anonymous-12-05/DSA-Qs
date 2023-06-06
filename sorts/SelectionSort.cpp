#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
int main(){
    int arr[10]={8,6,3,10,9,4,12,5,2,7};
    SelectionSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}