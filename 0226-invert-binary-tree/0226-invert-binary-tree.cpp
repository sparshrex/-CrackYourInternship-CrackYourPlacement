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
    TreeNode *solve(TreeNode*root)
    {
        if(root==NULL)
        {
            return NULL ;
        }
       swap(root->left,root->right);
        solve(root->left);
        solve(root->right);
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *node =solve(root);
        return node;
    }
};