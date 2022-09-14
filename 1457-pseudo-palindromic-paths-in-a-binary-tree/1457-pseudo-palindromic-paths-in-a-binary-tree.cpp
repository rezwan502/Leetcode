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
        
    int cnt = 0;
     void inOrder(TreeNode* node, vector<int> &fq) {
        if(!node) {
            return;
        }
        fq[node->val]++;
        
        if(!node->left && !node->right) {
            int odd = 0;
            for(int i=1; i<=9; i++) {
                if(fq[i] > 0 && fq[i]%2 == 0) {
                    continue;
                } else if (fq[i] > 0 && fq[i]%2 != 0){
                    odd++;
                }
            }
            if(odd <= 1) cnt++;
        } 
         
        inOrder(node->left, fq);
        inOrder(node->right, fq);
          
        fq[node->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> fq(10,0);
        inOrder(root, fq);
        return cnt;
    }
};