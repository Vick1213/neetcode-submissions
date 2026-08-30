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

    int res = 0;
    int goodNodes(TreeNode* root) {
        // find the biggest val you have encountered yet.

        // except root obv, 

        // use dfs 

        levelcheck(root,root->val);
       
        return res;
    }

    void levelcheck(TreeNode* node, int maxVal)
    {
        if(!node) return;
        if(node->val>=maxVal)
        {
            res = res +1;
            if(node->left)
            levelcheck(node->left,node->val);
            if(node->right)
            levelcheck(node->right,node->val);
        }
        else
        {
            
            levelcheck(node->left,maxVal);
            levelcheck(node->right,maxVal);
        }
    }
};
