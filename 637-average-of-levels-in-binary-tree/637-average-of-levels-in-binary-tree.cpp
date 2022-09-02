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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>Q;
        vector<double> ans;
        Q.push(root);
        
        while(!Q.empty()) {
            int sz = Q.size();
            double sum = 0.0;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = Q.front();
                Q.pop();
                
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                
                
                sum += (double) cur->val;
            }
            ans.push_back(sum/sz);
        }
        
        return ans;
    }
};