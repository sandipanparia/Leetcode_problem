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
    vector<vector<int>>res;
    void solve(TreeNode* root,vector<int>&tmp,int s, int targetSum){
        if(root==NULL)return;

        s+=root->val;
        tmp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
           if(s==targetSum) res.push_back(tmp);
           tmp.pop_back();
           return;
        }
        solve(root->left,tmp,s,targetSum);
        solve(root->right,tmp,s,targetSum);
        tmp.pop_back();
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int s=0;
        vector<int>tmp;
        solve(root,tmp,s,targetSum);
        return res;
    }
};
