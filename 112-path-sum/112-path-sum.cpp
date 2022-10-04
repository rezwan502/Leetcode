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
    bool isPathSumPossible(TreeNode* root, int targetSum) {
        //cout << root->val << " " << targetSum << endl;
        if (!root) return 0;
        if (!root->left && !root->right) return (targetSum - root->val ) == 0;
        return isPathSumPossible(root->left, targetSum - root->val) | isPathSumPossible(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isPathSumPossible(root, targetSum);
    }
};