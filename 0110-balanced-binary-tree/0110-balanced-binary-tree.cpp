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
bool a=0;
int rec(TreeNode*node)
{
    if(!node)return 0;
    int b=1+rec(node->left);
    int c=1+rec(node->right);
    if(abs(b-c)>1)a=1;
    return max(b,c);
}
    bool isBalanced(TreeNode* root) {
        rec(root);
    return !a;
    }
};