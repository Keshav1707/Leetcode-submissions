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
bool path(TreeNode* root,int x,string&s)
{
    if(root->val==x)return true;
    if(root->left&&path(root->left,x,s))s.push_back('L');
    else if(root->right&&path(root->right,x,s))s.push_back('R');
    return s.size();
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s,sa;
        path(root,startValue,s);
        path(root,destValue,sa);
        while(!s.empty() && !sa.empty() && s.back()==sa.back()){
            s.pop_back();
            sa.pop_back();
        }
        string temp="";
        for(auto i : s)
        {
            cout<<i<<endl;
            temp+='U';
        }
        reverse(sa.begin(),sa.end());
        temp+=sa;
        return temp;
    }
};