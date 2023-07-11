//https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
using namespace std;
string findLCS(int n, int m,string &s1, string &s2){

 

 n=s1.size(),m=s2.size();

 

        string s;

        int dp[n+1][m+1];

        for(int i=0;i<=n;i++)dp[i][0]=0;

        for(int i=0;i<=m;i++)dp[0][i]=0;

 

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];

                else {

                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

                }

            }

        }

       

        int i=n,j=m;

        while(i>0 && j>0){   

            if(s1[i-1]==s2[j-1]){

                s+=s1[i-1];   

                i--;j--;

            }

            else{

                if(dp[i][j-1]>dp[i-1][j])j--;    

                else i--;

            }

        }

        reverse (s.begin(),s.end());   

        return s;

}