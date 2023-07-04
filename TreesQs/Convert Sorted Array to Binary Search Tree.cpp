//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* solve(int left , int right , vector<int>&ans ){
        
        if(left>right){
            return nullptr;
        }
        int mid = left + (right-left)/2;
        
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = solve(left , mid-1 ,ans);
        root->right= solve(mid+1 , right , ans);
        return root;
}
    
    
TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    return solve(0,nums.size()-1,nums);
}