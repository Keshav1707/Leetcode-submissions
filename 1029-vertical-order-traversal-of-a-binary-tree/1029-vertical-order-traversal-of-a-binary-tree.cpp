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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode* n=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            m[x][y].insert(n->val);
            q.pop();
            if(n->left)q.push({n->left,{x-1,y+1}});
            if(n->right)q.push({n->right,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto i : m)
        {
            vector<int>temp;
            for(auto j : i.second)
            {
                for(auto x : j.second)
                {
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


























