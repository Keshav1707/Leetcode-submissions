/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(it==NULL)s+="#,";

            else 
            {
                q.push(it->left);
                q.push(it->right);
                s+=to_string(it->val)+',';
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#")return NULL;
        stringstream s(data);
        string temp;
        getline(s,temp,',');
        if (temp == "#") return NULL;
        TreeNode*root=new TreeNode(stoi(temp));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            if(getline(s,temp,','))
            {
                if(temp=="#")node->left=NULL;
                else
                {
                    node->left=new TreeNode(stoi(temp));
                    q.push(node->left);
                }
            }
            if(getline(s,temp,','))
            {
                if(temp=="#")node->right=NULL;
                else
                {
                    node->right=new TreeNode(stoi(temp));
                    q.push(node->right);
                }
            
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));