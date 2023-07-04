//https://leetcode.com/problems/validate-binary-search-tree/
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
bool validpoint(TreeNode *root,long long minval,long long maxval){
    if(root==NULL){return true;}
    if(root->val>=maxval || root->val<=minval){return false;}
    return validpoint(root->left,minval,root->val)&&validpoint(root->right,root->val,maxval);

}
bool isValidBST(TreeNode* root) {
    return validpoint(root,LONG_MIN,LONG_MAX);
}