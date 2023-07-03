//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
int findpos(vector<int>& inorder,int &ele,int &size){
        for(int i=0;i<size;i++){
            if(inorder[i]==ele)
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &size,int &preindex,int inorderstart,int inorderend){
        if((preindex>=size)||(inorderstart>inorderend))
            return NULL;

        int ele=preorder[preindex++];
        TreeNode* root=new TreeNode(ele);
        int pos=findpos(inorder,ele,size);
        root->left=solve(preorder,inorder,size,preindex,inorderstart,pos-1);
        root->right=solve(preorder,inorder,size,preindex,pos+1,inorderend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        int preindex=0,inorderstart=0,inorderend=size-1;
        return solve(preorder,inorder,size,preindex,inorderstart,inorderend);
    }