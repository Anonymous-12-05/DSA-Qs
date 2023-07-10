//https://leetcode.com/problems/climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
        int prev2=0,prev=1,curri;
        for(int i=1;i<=n;i++){
            curri=prev2+prev;
            prev2=prev;
            prev=curri;
        }
        return prev;
}