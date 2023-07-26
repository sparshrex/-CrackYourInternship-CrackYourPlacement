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
    
    int solve(TreeNode*root, bool isLeft)
    {
        if(root==NULL)return 0;
    
        if(root->left==NULL && root->right==NULL)
        {
            return isLeft ? root->val : 0;
        }
        return solve(root->left,true) + solve(root->right,false);
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
    }
};