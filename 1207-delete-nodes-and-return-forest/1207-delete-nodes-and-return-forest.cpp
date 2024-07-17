class Solution {
public:
    TreeNode* traverse(TreeNode* root, set<int>& to_delete_set, vector<TreeNode*>& forest) {
        if (!root) return nullptr;

        // Recursively traverse left and right subtrees
        root->left = traverse(root->left, to_delete_set, forest);
        root->right = traverse(root->right, to_delete_set, forest);

        // If the current node needs to be deleted
        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            if (root->left) forest.push_back(root->left);
            if (root->right) forest.push_back(root->right);
            delete root;
            return nullptr;
        }
        
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        
        if (to_delete_set.find(root->val) == to_delete_set.end()) {
            forest.push_back(root);
        }
        
        traverse(root, to_delete_set, forest);
        return forest;
    }
};