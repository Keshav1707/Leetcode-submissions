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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*>sta,stb;
        sta.push(root);
        while(!sta.empty())
        {
            stb.push(sta.top());
            auto n=sta.top();
            sta.pop();
            if(n->left)sta.push(n->left);
            if(n->right)sta.push(n->right);
        }
        vector<int>v;
        while(!stb.empty())
        {
            v.push_back(stb.top()->val);
            stb.pop();
        }
        return v;
    }
};