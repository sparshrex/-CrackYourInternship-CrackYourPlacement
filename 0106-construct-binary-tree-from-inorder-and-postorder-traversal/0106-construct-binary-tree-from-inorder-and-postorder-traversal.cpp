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
    unordered_map<int,int>m;

    TreeNode*build(vector<int>& inorder, vector<int>& postorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)return NULL;

        TreeNode*root = new TreeNode(postorder[pe]);
        int pos = m[root->val];
        int nsize = pos-is;

        root->left = build(inorder,postorder,ps,ps+nsize-1,is,pos-1);
        root->right= build(inorder,postorder,ps+nsize,pe-1,pos+1,ie);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i =0;i<inorder.size();i++)
        m[inorder[i]]=i;


        TreeNode*root = build(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1);

        return root;
    }
};