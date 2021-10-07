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
    int minDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
        queue<TreeNode * >q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            i++;
        int initSize=q.size();
        for(int j =0;j<initSize;j++){
            TreeNode * frontNode = q.front();
         if(frontNode->left){
             q.push(frontNode->left);
         }
        if(frontNode->right){
            q.push(frontNode->right);
        }
            q.pop();
          if(frontNode->left == NULL and frontNode->right == NULL){
                return i;
            }
        }
            }
        return 0;
        }
    
};