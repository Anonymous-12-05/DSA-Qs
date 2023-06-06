//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int a,b;
        for(int i=0;i<n;i++){

            int curr=arr[i];
            if(arr[abs(curr)-1]<0){
                a=abs(arr[i]);
            }
            else{
                arr[abs(curr)-1]=-arr[abs(curr)-1];
            }
        }
        for(int i=0;i<n;i++){
            int curr=arr[i];
            if(arr[i]>0){
                b=i+1;
                break;
            }
        }
        return {a,b};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends