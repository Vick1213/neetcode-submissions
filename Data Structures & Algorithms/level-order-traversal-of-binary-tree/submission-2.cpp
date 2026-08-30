class Solution {
public:
    vector<vector<int>> results;

    vector<vector<int>> levelOrder(TreeNode* root) {
        levelr(root, 0);
        return results;
    }

    void levelr(TreeNode* root, int level)
    {
        if (root == nullptr) return;

        if (level == results.size())
            results.push_back({});

        results[level].push_back(root->val);

        levelr(root->left, level + 1);
        levelr(root->right, level + 1);
    }
};