//https://leetcode.com/problems/binary-tree-preorder-traversal/
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
vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> preorder;
        // if(root){
        //     preorder.push_back(root->val);
        //     preorderTraversal(root->left);
        //     preorderTraversal(root->right);
        // }
        // return preorder;
        stack<TreeNode*>st;
        vector<int> preorder;
        //TreeNode *node=root;
        if(root==NULL) return preorder;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }

        }
        return preorder;
    }