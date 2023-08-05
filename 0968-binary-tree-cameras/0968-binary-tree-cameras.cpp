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
int sum =0;
    int solve(TreeNode*root)
    {
        if(root==NULL)return 1;

        int left = solve(root->left);
        int right = solve(root->right);

        if(left ==0 || right ==0)
        {
            sum++;
            return 2;
        }

        else if(left ==2 || right ==2)
        return 1;
     
        return 0;

    }


    int minCameraCover(TreeNode* root) {
        
    if(solve(root)==0)sum++;

    return sum;
    
    }
};