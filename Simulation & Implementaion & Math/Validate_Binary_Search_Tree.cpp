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
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
    
    bool valid(TreeNode* root, long MIN, long MAX) {
        if (!root) return true;
        if (root->val <= MIN || root->val >= MAX) return false;
        return valid(root->left, MIN, root->val) && valid(root->right, root->val, MAX);
    }
};