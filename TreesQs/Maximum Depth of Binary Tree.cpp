//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
int maxDepth(TreeNode* root) {
    // vector<vector<int>>ans;
    // if(root==NULL){return 0;}
    // queue<TreeNode*>q;
    // q.push(root);
    // while(!q.empty()){
    //     int size=q.size();
    //     vector<int>level;
    //     for(int i=0;i<size;i++){
    //         TreeNode* node=q.front();
    //         q.pop();
    //         if(node->left!=NULL){
    //             q.push(node->left);
    //         }
    //         if(node->right!=NULL){
    //             q.push(node->right);
    //         }
    //         level.push_back(node->val);
    //     }
    //     ans.push_back(level);
    // }      
    // return ans.size();  
    if(root!=NULL){
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
    return 0;
}