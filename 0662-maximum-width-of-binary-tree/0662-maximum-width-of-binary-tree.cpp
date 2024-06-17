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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxi=0;
        if(!root)return 0;
        while(!q.empty())
        {
            int n=q.size();
            int m=q.front().second;
            int first,last;
            for(int i=0;i<n;i++)
            {
                if(i==0)first=q.front().second;
                if(i==n-1)last=q.front().second;
                auto node=q.front().first;
                long long x=q.front().second-m;
                q.pop();
                if(node->left)q.push({node->left,2*x+1});
                if(node->right)q.push({node->right,2*x+2});
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};