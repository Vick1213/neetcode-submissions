class Solution {
public:
    int maxPath = INT_MIN;

    int maxPathSum(TreeNode* root) {
        maxPathSum_recurr(root);
        return maxPath;
    }

    int maxPathSum_recurr(TreeNode* root) {
        if (!root) return 0;

        int left  = max(maxPathSum_recurr(root->left), 0);
        int right = max(maxPathSum_recurr(root->right), 0);

        maxPath = max(maxPath, root->val + left + right);

        return root->val + max(left, right);
    }
};