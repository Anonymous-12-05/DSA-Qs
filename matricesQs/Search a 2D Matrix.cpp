//https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h> 
using namespace std; 
// int binsearch(vector<int> arr,int x){
//     int low=0,high=arr.size();
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid]==x){
//             return 1;
//         }
//         else if(arr[mid]>x){
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return 0;
// }
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     for(int i=0;i<matrix.size();i++){
//         if(binsearch(matrix[i],target)==1){
//             return true;
//         }
//     }
//     return 0;
// }
bool searchMatrix(vector<vector<int>>& matrix, int target){
    if(matrix.size()==0){return false;}
    int n=matrix.size(),m=matrix[0].size();
    int low=0,high=(m*n)-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(matrix[mid/m][mid%m]==target){
            return true;
        }
        else if((matrix[mid/m][mid%m]<target)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
int  main(){
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    cout<<searchMatrix(matrix,target);
}