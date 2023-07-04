//https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
public:
    vector<int> ans;
    queue<int>q;
    BSTIterator(TreeNode* root) {
    
        
        inorder(root , ans);
        pushing(q);

    }
    void inorder(TreeNode *root,vector<int>&ans){
        
        if(root==NULL)
        return ;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }
    void pushing(queue<int>&q){
        for(int i=0;i<ans.size();i++){
        q.push(ans[i]);
    }  
    }   

    int next() {
        
        int a=q.front();
        q.pop();
        return a;

    }
    
    bool hasNext() {
        if(q.empty()){return false;}
        return true;
    }
};