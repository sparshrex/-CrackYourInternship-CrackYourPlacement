/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void Parentmark(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m)
{
    queue<TreeNode*>q;
    q.push(root);
    // m[root]==NULL;
    while(!q.empty())
    {
        TreeNode*front = q.front();
        q.pop();


        if(front->left)
        {
            m[front->left]=front;
            q.push(front->left);
        }

        if(front->right)
        {
            m[front->right]=front;
            q.push(front->right);
        }

    }
}


vector<int>distance(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m,TreeNode*target,int k)
{
    int curr_level =0;
    queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>visited;
    q.push(target);
    visited[target]=true;
    while(!q.empty())
    {
        
        int size = q.size();
        if(curr_level==k)break;
        for(int i=0;i<size;i++)
        {
            TreeNode*front = q.front();
            q.pop();

            if(front->left  && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left]=true;
            }

             if(front->right  && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right]=true;
            }

            if(m[front] && !visited[m[front]])
            {
                q.push(m[front]);
                visited[m[front]]=true;
            }
        
        }
        curr_level++;

    }
    vector<int>ans;
    while(!q.empty())
    {
        TreeNode*curr = q.front();
        q.pop();

        ans.push_back(curr->val);
    }
    return ans;

}


    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*,TreeNode*>m;

    Parentmark(root,m);
    return distance(root,m,target,k);
    }
};