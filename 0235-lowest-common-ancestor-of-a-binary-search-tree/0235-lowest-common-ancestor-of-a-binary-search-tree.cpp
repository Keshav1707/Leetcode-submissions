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
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode*node=root;
        while(1)
        {
            if(node->val>p->val&&node->val>q->val)node=node->left;
            else if(node->val<p->val&&node->val<q->val)node=node->right;
            else return node;
        }
    }
};