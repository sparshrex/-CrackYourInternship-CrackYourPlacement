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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
      queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
       while(!q.empty())
       {
           TreeNode*curr= q.front();
          
           q.pop();
           
          
           //last node level
           if(curr==NULL)
           {
               
               res.push_back(ans);
               ans.clear();
               //make the last node of upcoming level
               if(!q.empty())
                   q.push(NULL);
               
           }
           else
           {ans.push_back(curr->val);
                 if(curr->left)
            {
                
                q.push(curr->left);
            }
           if(curr->right)
           {
               q.push(curr->right);
           }
           }
            
       }
        return res;
    }
};