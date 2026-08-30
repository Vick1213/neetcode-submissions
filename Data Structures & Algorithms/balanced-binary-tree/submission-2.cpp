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
bool isbal = true;
    bool isBalanced(TreeNode* root) {
  if(!root) return true;

       /// calc height left compare with right return if |left-right|>1\

        // int left = height(root->left);
        // int right = height(root->right);
        // if(abs(right - left) > 1)
        // {
        //     return false;
        // }
        height(root);
        return isbal;
        
    }

    int height(TreeNode*root)
    {
        if(!root) return 0;
        int left =height(root->left);
        int right = height(root->right);
             if(abs(right - left) > 1)
        {
            isbal = false;;
        }
            return 1 + max(left,right);


    }
};
