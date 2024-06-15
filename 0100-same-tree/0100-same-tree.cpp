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

bool rec(TreeNode*nodea,TreeNode*nodeb)
{
    if(!nodea||!nodeb)
    {
        return nodea==nodeb;
    }
    return (nodea->val==nodeb->val)&&rec(nodea->left,nodeb->left)&&rec(nodea->right,nodeb->right);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return rec(p,q);
    }
};