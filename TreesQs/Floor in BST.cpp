//https://www.codingninjas.com/studio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

void inorder(TreeNode<int> *root,vector<int>&ans){
        
        if(root==NULL)
        return ;
        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }

int floorInBST(TreeNode<int> * root, int X)
{
    vector<int> ans;
        
        inorder(root , ans);
        
        int n=ans.size();
        int successor=-1;
        int predeccesor=-1;
        // for(int i=0;i<n;i++){
        //     if(ans[i]>X){
        //         successor=ans[i];
        //         break;
        //     }
            
        // }
        
        for(int i=n-1;i>=0;i--){
            
            if(ans[i]<=X){
                predeccesor=ans[i];
                break;
            }
            
        }
        return predeccesor;
        
        // Write your code here.
}