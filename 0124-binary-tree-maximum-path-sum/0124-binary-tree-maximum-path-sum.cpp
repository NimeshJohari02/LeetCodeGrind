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
    int maxSum = INT_MIN;
    int driver(TreeNode *root){
         if(root == nullptr) return 0 ;
        int leftSum = max(0,driver(root->left));// Do not consider paths that have negative sum ;
//         if(leftSum < 0) leftSum =0 ;
        int rightSum = max(0,driver(root->right));
//         if(rightSum < 0 )rightSum = 0 ;
        maxSum = max(maxSum , leftSum + rightSum + root->val);
        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
       int temp = driver(root);
       return   maxSum ;
    }
};