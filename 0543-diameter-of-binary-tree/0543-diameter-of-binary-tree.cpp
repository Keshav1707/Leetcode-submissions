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
int maxi=0;
int rec(TreeNode*node)
{
    if(!node)return 0;
    int a=1+rec(node->left);
    int b=1+rec(node->right);
    maxi=max(maxi,a+b-2);
    return max(a,b);
}
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return maxi;
    }
};