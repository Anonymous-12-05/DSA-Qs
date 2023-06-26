//https://leetcode.com/problems/binary-tree-inorder-traversal/
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
vector<int> inorderTraversal(TreeNode* root) {
    // vector<int> ans;
    // inorderTraversal(root->left);
    // ans.push_back(root->val);
    // inorderTraversal(root->right);
    // return ans;
    stack<TreeNode*>st;
    TreeNode * node=root;
    vector<int> inorder;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()==true){
                break;
            }
            node=st.top();
            st.pop();
            inorder.push_back(node->val);
            node=node->right;
        }
    }
    return inorder;

}