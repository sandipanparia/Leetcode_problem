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
    TreeNode* deletehelper(unordered_set<int>&st,vector<TreeNode*>&res,TreeNode* root){
        if(root==NULL)return NULL;

        root->left=deletehelper(st,res,root->left);
        root->right=deletehelper(st,res,root->right);

        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL)res.push_back(root->left);
            if(root->right!=NULL)res.push_back(root->right);
            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>res;
        unordered_set<int>st;
        for(auto it:to_delete){
            st.insert(it);
        }
        deletehelper(st,res,root);
        if(st.find(root->val)==st.end()){
            res.push_back(root);
        }
        return res;
    }
};
