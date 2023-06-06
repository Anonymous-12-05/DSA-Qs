//https://www.spoj.com/problems/ANARC05B/
#include <bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        else{
            int arr1[n];
            int m,arr2[m];
            for(int i=0;i<n;i++){
                cin>>arr1[i];
            }
            cin>>m;
            for(int i=0;i<m;i++){
                cin>>arr2[i];
            }
            int s1=0,s2=0,i=0,j=0,ma=0;
            while(i<n && j<m){
                if(arr1[i]<arr2[j]){
                    s1+=arr1[i++];
                }
                else if(arr1[i]>arr2[j]){
                    s2+=arr2[j++];
                }
                else{
                    ma=ma+max(s1,s2)+arr1[i];
                    s1=s2=0;
                    i++;
                    j++;
                }
            }
            for(;i<n;i++){
                s1+=arr1[i];
            }
            for(;j<m;j++){
                s2+=arr2[j];
            }
            ma+=max(s1,s2);
            cout<<ma<<endl;
        }
    }
}