#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l,j=h;
    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }while(i<j);
    swap(arr[l],arr[j]);
    return j;
}
void QuickSort(int arr[],int l,int h){
    int j;
    if(l<h){
        j=partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}

int main(){
    int arr[11]={8,6,3,10,9,4,12,5,2,7,INT32_MAX};
    QuickSort(arr,0,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}