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
    vector<vector<int>> possiblePath;
    
    void dfs(TreeNode* root, int curSum, int targetSum, vector<int> &path) {
        if(root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            
            if(targetSum == curSum + root->val) {
                possiblePath.push_back(path);
            }
            
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        if (root->left != nullptr) {
            dfs(root->left, curSum + root->val ,targetSum , path);
        }
        if (root->right != nullptr) {
            dfs(root->right, curSum + root->val, targetSum , path);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<int> path;
        dfs(root, 0, targetSum, path);
        return possiblePath;    
    }
};