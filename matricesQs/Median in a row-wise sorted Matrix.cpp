//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmallerThanMid(vector<int> &row,int mid){
        int low=0,high=row.size()-1;
        while(low<=high){
            int md=(low+high)/2;
            if(row[md]<=mid){
                low=md+1;
            }
            else{
                high=md-1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // vector<int> arr={};
        // for(int i=0;i<R;i++){
        //     for(int j=0;j<C;j++){
        //         arr.push_back(matrix[i][j]);
        //     }
        // }
        // sort(arr.begin(),arr.end());
        // return arr[arr.size()/2];
    // code here     
    int low=1;
    int high=1e9;
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=0;
        for(int i=0;i<R;i++){
            cnt+=countSmallerThanMid(matrix[i],mid);
        }
        if(cnt<=(R*C)/2){low=mid+1;}
        else{
            high=mid-1;
        }
    }
    return low;    
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends