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
    int res;
    pair<int,int> solve(TreeNode* root){
        if(!root)return {0,0};

        auto x=solve(root->left);
        auto y=solve(root->right);

        int s=x.first+y.first+root->val;
        int cnt=x.second+y.second+1;
        if(root->val==(s/cnt))res++;

        return {s,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        res=0;
        solve(root);
        return res;
    }
};
