/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q){
            return root;
        }
        TreeNode* root1 = dfs(root->left,p,q);
        TreeNode* root2 = dfs(root->right,p,q);
        
        if(root1 && root2){
            return root;
        }
        
        if(!root1) return root2;
        
        return root1;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = dfs(root,p,q);
        return ans ;
    }
};