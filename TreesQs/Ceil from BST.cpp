//https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
#include <bits/stdc++.h> 
using namespace std;


  

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };


void inorder(BinaryTreeNode<int> *root,vector<int>&ans){
        
        if(root==NULL)
        return ;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
    }


int findCeil(BinaryTreeNode<int> *root, int x){
    vector<int> ans;
        
        inorder(root , ans);
        
        int n=ans.size();
        int successor=-1;
        int predeccesor=-1;
        for(int i=0;i<n;i++){
            if(ans[i]>=x){
                successor=ans[i];
                break;
            }
            
        }
        
        // for(int i=n-1;i>=0;i--){
            
        //     if(ans[i]<=x){
        //         predeccesor=ans[i];
        //         break;
        //     }
            
        // }
        return successor;// Write your code here.
}