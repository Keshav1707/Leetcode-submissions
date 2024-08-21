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
bool trav(TreeNode*lf,TreeNode*rt)
{
    if(!lf&&!rt)return 1;
    if(!lf||!rt)return 0;
    bool a=1;
    if(lf->val==rt->val)
    {
        a=a&trav(lf->left,rt->right);
        a=a&trav(lf->right,rt->left);
    }
    else a=0;
    return a;
    
}
    bool isSymmetric(TreeNode* root) {
        return trav(root->left,root->right);
    }
};