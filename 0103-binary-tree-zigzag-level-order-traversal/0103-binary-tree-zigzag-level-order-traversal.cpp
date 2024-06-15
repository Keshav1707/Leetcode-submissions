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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(!root)return {};
        bool f=0;
        vector<vector<int>>ans;
        while(!q.empty())
        {
            
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                auto it =q.front();
                    
                    if(it->left)q.push(it->left);
                    if(it->right)q.push(it->right);
                
                temp.push_back(it->val);
                q.pop();
            }
            if(f)reverse(temp.begin(),temp.end());
            f=!f;
            ans.push_back(temp);
        }
        return ans;
    }
};