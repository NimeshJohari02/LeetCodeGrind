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
    int totalSum =0;
    void helper(TreeNode *root , int currentNum =0 ){
        if(root == NULL)
        {
            return ;
        }
        if(root->left == NULL && root->right == NULL) {
        currentNum = currentNum << 1;
        currentNum = currentNum | root->val;
        totalSum += currentNum ;
            return ;
        }
        currentNum = currentNum << 1;
        currentNum = currentNum | root->val;
        helper(root->left , currentNum);
        helper(root->right , currentNum);
        return;
    }
    int sumRootToLeaf(TreeNode* root ) {
        if(root == NULL){
            return 0;
        }
        int currentNum =0;
        helper(root , currentNum);
        return totalSum;
    }
};