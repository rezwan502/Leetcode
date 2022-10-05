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
    /*
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
                for(int i=0; i<Q.size(); i++) {
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
    } */
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode *newnode = new TreeNode(v);
            newnode->left=root;
            return newnode;
        }
        
        queue<TreeNode*> q;
        q.push(root);
    
        int i=1;
        while(!q.empty()){
            i++;
            if(i==d) break;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right); 
            }
        }
        
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front(); q.pop();
            TreeNode* l = temp->left, *r = temp->right;
            temp->left= new TreeNode(v);
            temp->left->left=l;
            temp->right= new TreeNode(v);
            temp->right->right=r;
        }
        return root;
    }
};