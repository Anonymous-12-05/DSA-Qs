//Construct Binary Tree from Inorder and Postorder Traversal
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
int linearSearch(int element,vector<int>& inorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(element==inorder[i])
                return i;
        }
        return -1;
    }
    TreeNode* solve(int& idx,int start,int end,vector<int>& inorder,vector<int>& postorder){
        if(start>end || idx<0) return NULL;
        int element=postorder[idx];
        idx--;
        int pos=linearSearch(element,inorder);
        TreeNode* root=new TreeNode(element);
        root->right=solve(idx,pos+1,end,inorder,postorder);
        root->left=solve(idx,start,pos-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        int n=inorder.size();
        int lastpos=n-1;
        root=solve(lastpos,0,n-1,inorder,postorder);
        return root;
    }