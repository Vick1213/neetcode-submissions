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

   int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> treeStack;
    TreeNode* node = root;

    while (node != nullptr || !treeStack.empty())
    {
        while (node != nullptr)
        {
            treeStack.push(node);
            node = node->left;
        }
        node = treeStack.top();
        treeStack.pop();
        k--;
        if (k == 0) return node->val;
        node = node->right;
    }

    return -1; // unreachable given valid k per constraints, but avoids a fallthrough warning
}
};
