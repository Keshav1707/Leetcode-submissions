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
TreeNode*rec(vector<int>&v,int&ind,int prev)
{
    if(ind==v.size()||prev<v[ind])return NULL;
    TreeNode*node=new TreeNode(v[ind]);
    ind++;
    node->left=rec(v,ind,node->val);
    
    node->right=rec(v,ind,prev);
    return node;
}
    TreeNode* bstFromPreorder(vector<int>& v) {
        
        int ind=0;
        
        return rec(v,ind,INT_MAX);
    }
};