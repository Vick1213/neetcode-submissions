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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // search BST for p or q 
        // whatever found first, find it in the sub tree if not in subtree COOOKED;;


        if(p->val == root->val && (q->val< root->val || q->val>root->val))
        {
            return p;
        }

        if(q->val == root->val && (p->val< root->val || p->val>root->val))
        {
            return q;
        }

        if(p->val <root->val  && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p,q);
        }
        else if(p->val >root->val  && q->val > root->val)
        {
             return lowestCommonAncestor(root->right, p,q);
        }
        if(p->val >root->val  && q->val < root->val ||p->val <root->val  && q->val > root->val  )
        {
            return root;
        }


    }

    TreeNode* bstSearch(TreeNode* root, TreeNode* p)
    {
        if(root->val<p->val)
        {
            bstSearch(root->right,p);
        }
        else if(root->val>p->val)
        {
            bstSearch(root->left,p);
        }
        else if(root->val == p->val)
            return root;
    }
};
