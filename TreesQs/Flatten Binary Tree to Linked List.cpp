//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
TreeNode* previous=NULL;
void flatten(TreeNode* node) {
        if(node==NULL){return ;}
        flatten(node->right);
        flatten(node->left);
        node->right=previous;
        node->left=NULL;
        previous=node;
}