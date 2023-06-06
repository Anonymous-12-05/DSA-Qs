#include <bits/stdc++.h>
using namespace std;
void shellsort(int arr[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap=gap/2){
        for(i=gap;i<n;i++){
            temp=arr[i];
            j=i-gap;
            while(j>=0 && arr[j]>temp){
                arr[j+gap]=arr[j];
                j-=gap;
                
            }
            arr[j+gap]=temp;
        }
    }
}
int main(){
    int arr[10]={8,6,7,7,8,4,12,5,7,7};
    shellsort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}