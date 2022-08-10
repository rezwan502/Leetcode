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
    
    bool f(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == nullptr || rightRoot == nullptr) return leftRoot == rightRoot;
        
        if(leftRoot -> val != rightRoot->val) return false;
        
        bool lf= f(leftRoot->left, rightRoot->right);
        bool rf = f(leftRoot->right, rightRoot->left);
        
        return lf&&rf;
    }
    
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || f(root->left, root->right);
    }
};