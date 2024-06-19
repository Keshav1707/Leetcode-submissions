/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void findp(TreeNode*node,unordered_map<TreeNode*,TreeNode*>&mp)
{
    if (!node) return;

        if (node->left) {
            mp[node->left] = node;
            findp(node->left, mp);
        }

        if (node->right) {
            mp[node->right] = node;
            findp(node->right, mp);
        }

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        findp(root,mp);
        queue<TreeNode*>q;
        q.push(target);
        int dis=0;
        map<TreeNode*,bool>vis;
        vis[target]=1;
        while(!q.empty())
        {
            int n=q.size();
            if(dis++==k)break;
            for(int i=0;i<n;i++)
            {
            auto node=q.front();

            q.pop();
            
            if(node->left&&vis[node->left]==0)
            {
                q.push(node->left);
                vis[node->left]=1;
                
            }
            if(node->right&&vis[node->right]==0)
            {
                q.push(node->right);
                vis[node->right]=1;
            }
            if(mp[node]&&vis[mp[node]]==0)
            {
                q.push(mp[node]);
                vis[mp[node]]=1;
            }
            }
            cout<<dis<<endl;
            if(dis==k)break;
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};