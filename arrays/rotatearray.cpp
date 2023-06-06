// { Driver Code Starts
//Initial Template for C++
//https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++

void rotate(int arr[], int n)
{
    int dup[n];
    int x=arr[n-1];
    dup[0]=x;
    for(int i=1;i<n;i++){
        dup[i]=arr[i-1];
    }
    for(int i=0;i<n;i++){
        arr[i]=dup[i];
    }
    
        
}