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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        vector<int>ans;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            TreeNode* temp;
            
            int n, x;
            n = Q.size();
            
            for(int i=0; i<n; i++){
                temp = Q.front(); Q.pop();
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
                x = temp->val;
            }
            ans.push_back(x);
        }
        
        
        return ans;
    }
};