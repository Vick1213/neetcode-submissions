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


    vector<vector<int>> results;
    vector<int> rightSideView(TreeNode* root) {

        vector<int> results_final;

        levelr(root,0);
        for (vector<int> &result: results)
        {
            results_final.push_back(result.back());
        }

        return results_final;
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
