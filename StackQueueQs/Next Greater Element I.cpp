//https://leetcode.com/problems/next-greater-element-i/
#include<bits/stdc++.h>
using namespace std;
// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
//         int H[nums2.size()];
//         vector<int>v,sln;
//         stack<int> st;
//         for(int i=nums2.size()-1;i>=0;i--){
//             if(st.size()==0){
//                 v.push_back(-1);
//                 //H[nums2[i]]=v[i];
//             }
//             else if(st.size()>0 && st.top()>nums2[i]){
//                 v.push_back(st.top());
//                 //H[nums2[i]]=v[i];
//             }
//             else if(st.size()>0 && st.top()<=nums2[i]){
//                 while(st.size()>0 && st.top()<=nums2[i]){
//                     st.pop();
//                 }
//                 if(st.size()==0){
//                     v.push_back(-1);
//                     //H[nums2[i]]=v[i];
//                 }
//                 else{
//                     v.push_back(st.top());
//                     //H[nums2[i]]=v[i];
//                 }
//             }
//             st.push(nums2[i]);
//         }
//         int j=0,x=0;
//         while(j<nums2.size() && x<v.size()){
//             H[nums2[j++]]=v[x++];
//         }
//         for(int i=0;i<nums1.size();i++){
//             sln.push_back(H[nums1[i]]);
//         }
//         return sln;
// }
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums) {
        int n = nums.size();
        int H[nums.size()];
      vector < int > nge(n, -1),sln;
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      for(int i=n-1;i>=0;i++){
        nge[i]=-1;
        break;
      }
      int j=0,x=0;
        while(j<nums.size() && x<nge.size()){
            H[nums[j++]]=nge[x++];
        }
        for(int i=0;i<nums1.size();i++){
            sln.push_back(H[nums1[i]]);
        }
        return sln;
      //return nge;
   
}
// vector < int > nextGreaterElements(vector < int > & nums) {
//       int n = nums.size();
//       vector < int > nge(n, -1);
//       stack < int > st;
//       for (int i = 2 * n - 1; i >= 0; i--) {
//         while (!st.empty() && st.top() <= nums[i % n]) {
//           st.pop();
//         }

//         if (i < n) {
//           if (!st.empty()) nge[i] = st.top();
//         }
//         st.push(nums[i % n]);
//       }
//       return nge;
//     }
int main(){
    vector<int> nums1={4,1,2},nums2={1,3,4,2};
    vector<int >v=nextGreaterElement(nums1,nums2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}