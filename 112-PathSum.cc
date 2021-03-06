/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//version 1
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!root->left && !root->right)
            return sum==root->val;
        return (root->left && hasPathSum(root->left,sum-root->val))||(root->right && hasPathSum(root->right,sum-root->val));
    }
};

//version 2
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return root && 
            ((!root->left &&!root->right)?(sum==root->val):
              (hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val)));
    }
};
