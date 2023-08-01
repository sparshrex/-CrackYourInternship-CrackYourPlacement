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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans = 0;
        

       while(!q.empty())
       {
           int size= q.size();
            int first,last;
           int mini = q.front().second;
           for(int i=0;i<size;i++)
           {
           TreeNode*front = q.front().first;
            int cur_id = q.front().second-mini;
            q.pop();


           if(i==0)first = cur_id;
           if(i ==size-1)last = cur_id;

          

           if(front->left)
           q.push({front->left,(long long)2*cur_id+1});

           if(front->right)
           q.push({front->right,(long long)2*cur_id+2});


           }


        ans= max(ans,last-first+1);
       }
       
        

        
        return ans;
    }
};