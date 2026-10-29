#include<iostream>
using namespace std;

bool isMirror(TreeNode* a , TreeNode* b){
    if(a==NULL && b==NULL){
        return true;
    }
    if(a==NULL || b==NULL || a->val != b->val){
        return false;
    }
    return isMirror(a->left,b->right) && isMirror(a->right,b->left);
}

bool isSimilar(TreeNode root){
    return isMirror(root->left,root->right);
}