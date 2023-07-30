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
// void _inorderTraversal(TreeNode*root,vector<int>&ans)
// {
//      if(root!=NULL)
//         {
//             _inorderTraversal(root->left,ans);
//             ans.push_back(root->val);
//             _inorderTraversal(root->right,ans);
//         }
// }



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int>inorder;
    TreeNode*cur = root;

    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode*prev = cur->left;
            while(prev->right && prev->right!=cur)
            prev = prev->right;

        if(prev->right==NULL)
        {
            prev->right = cur;
            cur=cur->left;
        }
        //remvoe thred
        else{
            prev->right =NULL;
            inorder.push_back(cur->val);
            cur=cur->right;
        }

        }
        //make a thread...
       
        


    }
     return inorder;
        

    }
};