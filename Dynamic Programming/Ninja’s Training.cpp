//https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
using namespace std;
int f(int day,int last, vector<vector<int>>&points, vector<vector<int>>&dp){
    
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1){return dp[day][last];}
    int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
            int point=points[day][i]+f(day-1,i,points,dp);
            maxi=max(maxi,point);
            }
    }
    return dp[day][last]= maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);// Write your code here.
}

int ninjaTrainingTabulation(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));
    for(int day=1;day<n;day++){
        for(int last=0;last<=3;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                   int point=points[day][task]+dp[day-1][task];
                   dp[day][last]=max(dp[day][last],point);
            }
            }

        }
    }
    return dp[n-1][3];// Write your code here.
}