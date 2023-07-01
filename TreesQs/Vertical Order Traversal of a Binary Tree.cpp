//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
      queue<pair<TreeNode*,int>>q;
      map<int,int>mpp;
      q.push({root,0});
      vector<vector<int>>ans;
      while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode *node=it.first;
        int line=it.second;
        mpp[line]=node->val;
        if(node->left!=NULL){
            q.push({node->left,line+1});

        }
        if(node->right!=NULL){
            q.push({node->right,line-1});
            
        }

        }
    vector<int>v;
    for(auto it:mpp){
        //vector<int>v;

        v.push_back(it.second);

    }
    ans.push_back(v);
}