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
int maxi=INT_MIN;
int rec(TreeNode* node)
{
    if(node==nullptr)
    {
        return 0;
    }
    int a=max(0,rec(node->left));
    int b=max(0,rec(node->right));
    maxi=max(maxi,a+b+node->val);
    return node->val+max(a,b);
}
    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxi;
    }
};