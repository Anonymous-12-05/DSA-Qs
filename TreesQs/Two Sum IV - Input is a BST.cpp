//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
void inorder(TreeNode *root,vector<int>&ans){
        
        if(root==NULL)
        return ;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }

bool findTarget(TreeNode* root, int k) {
    vector<int>ans;
    inorder(root,ans);
    int l=0,r=ans.size()-1;
    while(l<r){
        if(ans[l]+ans[r]==k){return true;}
        else if(ans[l]+ans[r]>k){
            r--;
        }
        else{
            l++;
        }
    }
    return false;
}