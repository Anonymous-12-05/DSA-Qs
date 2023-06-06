#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int arr[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=0;
            }
        }
        if(flag==0){return ;}
    }
}
int main(){
    int arr[6]={2,3,4,5,6,7};
    BubbleSort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}