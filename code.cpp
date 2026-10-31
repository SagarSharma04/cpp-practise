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


void topview(Node* root){
    queue<pair<Node* , int>>q;
    map<int,int>m;
    q.push(root,0);
    while(q.size()>0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if(m.find(currHD)==m.end()){
            m[currHD] = curr->data;
        }
        if(curr->left != NULL){
            q.push(curr->left,currHD-1);
        }
        if(curr->right != NULL){
            q.push(curr->right,currHD+1);
        }
    }

    for(auto it : m){
        cout<<it.second<<" ";
    }
}