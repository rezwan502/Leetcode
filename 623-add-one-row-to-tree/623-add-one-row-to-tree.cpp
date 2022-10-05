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
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
        int level = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            level++;
            
            if (depth - 1 == level) {
                break;
            } else {
                int sz = Q.size();
                for(int i=0; i<sz; i++) {
                    TreeNode* cur = Q.front();
                    Q.pop();
                    if(cur->left) Q.push(cur->left);
                    if(cur->right) Q.push(cur->right);
                }
            }
        }
        
         while(!Q.empty()) {
            TreeNode* cur = Q.front();
            Q.pop();
            
            TreeNode* left = cur->left;
            TreeNode* right = cur->right;
             
            cur->left= new TreeNode(val);
            cur->left->left=left;
            cur->right= new TreeNode(val);
            cur->right->right=right;
        }
        
        return root;
    } 
};