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
void dfs(TreeNode*node,vector<int>&v)
{
    if(!node)return;
    dfs(node->left,v);
    v.push_back(node->val);
    dfs(node->right,v);
}
TreeNode*blc(int beg,int end,vector<int>&v)
{
    if(beg>end)return nullptr;
    int mid=(beg+end)>>1;
    return new TreeNode(v[mid],blc(beg,mid-1,v),blc(mid+1,end,v));
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>srt;
        dfs(root,srt);
        return blc(0,srt.size()-1,srt);
    }
};