//https://practice.geeksforgeeks.org/problems/count-squares3649/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // int count=0,i;
        // for(i=1;i<N;){
        //     if(i<N){
        //         count++;
        //     }
        //     i++;
        //     i=pow(i,2);
        // }
        // return count;
        int a=sqrt(N);
        if(a==sqrt(N)){return a-1;}
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends