/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int n = q.size();
            vector<int>res(n);
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                int ind=0;
                if(flag){
                    ind = i;
                }else{
                    ind = n-1-i;
                }
                res[ind] = curr->val;
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
            flag = !flag;
            ans.push_back(res);
        }
        return ans;
    }
};