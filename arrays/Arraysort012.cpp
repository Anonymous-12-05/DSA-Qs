//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int c0,c1,c2;
        c0=c1=c2=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                c0++;
            }
            if(a[i]==1){
                c1++;
            }
            if(a[i]==2){
                c2++;
            }
        }
        for(int i=0;i<c0;i++){
            a[i]=0;
        }
        for(int i=c0;i<(c0+c1);i++){
            a[i]=1;
        }
        for(int i=(c0+c1);i<n;i++){
            a[i]=2;
        }

        
    }    // code here 
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends