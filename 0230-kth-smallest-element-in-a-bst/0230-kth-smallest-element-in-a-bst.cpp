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

void trv(TreeNode*node,int&k,int&ans,int n)
{
    if(!node||ans!=-1)return;
    trv(node->left,k,ans,n);
    k++;
    if(k==n)
    {
        ans=node->val;
        return;
    }
    trv(node->right,k,ans,n);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int a=0;
        trv(root,a,ans,k);
        return ans;
    }
};