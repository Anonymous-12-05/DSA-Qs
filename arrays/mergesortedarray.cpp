//https://leetcode.com/problems/merge-sorted-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //last index nums1
        int last=m+n-1;
        while(m>0 && n>0){
            if(nums1[m-1]>nums2[n-1]){
                nums1[last]=nums1[m-1];
                m--;
            }
            else{
                nums1[last]=nums2[n-1];
                n--;
            }
            last--;
            //fill nums1 with leftover elements in nums2
            while(n>0){
                nums1[last]=nums2[n-1];
                n--;last--;
            }
        }

    }*/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }

        }
        while(i>=0){
            nums1[k--]=nums1[i--];
        }
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};