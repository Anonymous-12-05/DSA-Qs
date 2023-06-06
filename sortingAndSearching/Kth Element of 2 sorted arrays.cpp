//{ Driver Code Starts
//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // void merge(int nums1[], int m, int nums2[], int n) {
    //     int i=m-1,j=n-1,k=m+n-1;
    //     while(i>=0 && j>=0){
    //         if(nums1[i]>nums2[j]){
    //             nums1[k]=nums1[i];
    //             i--;
    //             k--;
    //         }
    //         else{
    //             nums1[k]=nums2[j];
    //             j--;
    //             k--;
    //         }

    //     }
    //     while(i>=0){
    //         nums1[k--]=nums1[i--];
    //     }
    //     while(j>=0){
    //         nums1[k--]=nums2[j--];
    //     }
    // }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0,kth=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                kth++;
                if(kth==k){
                    return arr1[i];
                }
                i++;
            }
            else{
                kth++;
                if(kth==k){
                    return arr2[j];
                }
                j++;
            }
        }
        while(i<n){
            kth++;
                if(kth==k){
                    return arr1[i];
                }
                i++;
        }
        while(j<m){
            kth++;
                if(kth==k){
                    return arr2[j];
                }
                j++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends