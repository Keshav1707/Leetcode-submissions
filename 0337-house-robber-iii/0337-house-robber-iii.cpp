class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        int dontRob = rob(root -> left) + rob(root -> right), robRoot = root -> val;
        if(root -> left) robRoot += rob(root -> left -> left) + rob(root -> left -> right);
        if(root -> right) robRoot += rob(root -> right -> left) + rob(root -> right -> right);
        return dp[root] = max(dontRob, robRoot);
    }
};