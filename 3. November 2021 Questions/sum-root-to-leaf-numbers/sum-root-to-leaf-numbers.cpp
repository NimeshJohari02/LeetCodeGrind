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
    int helper(TreeNode *root , int cs){
        if(root == NULL){
            return 0;
        }
        cs = cs*10+root->val;
        if(root ->left == NULL and root->right ==  NULL){
            return cs;
        }
        int left =0;
        int right =0;
        if(root->left) {
         left = helper(root->left , cs);
        }
        if(root ->right){
            right = helper(root->right , cs);
        }
        return left + right ;
    }
    int sumNumbers(TreeNode* root) {
       return helper(root , 0 );
    }
};