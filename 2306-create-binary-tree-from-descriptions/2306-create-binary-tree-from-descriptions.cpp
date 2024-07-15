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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>m;
        set<int>v,va;
        for(auto i : descriptions)
        {
            TreeNode*temp;
            v.insert(i[0]);
            va.insert(i[1]);
            if(m.find(i[0])==m.end())
            {
                temp=new TreeNode(i[0]);
                
                m[i[0]]=temp;
                
            }
            else
            {
               temp=m[i[0]];
            }
            if(i[2]==1)
            {
                if(m.find(i[1])==m.end())
                {
                    temp->left=new TreeNode(i[1]),m[i[1]]=temp->left,va.insert(i[1]);
                    
                }
                else 
                {
                    temp->left=m[i[1]];
                }
                
            }
                else
                {
                    if(m.find(i[1])==m.end())
                    {
                        temp->right=new TreeNode(i[1]),m[i[1]]=temp->right,va.insert(i[1]);
                        
                    }
                    else
                    {
                        temp->right=m[i[1]];
                    }
                } 

            
        }
        for(auto i : v)
        {
            if(va.find(i)==va.end())return m[i];
        }
        return nullptr;
    }
};