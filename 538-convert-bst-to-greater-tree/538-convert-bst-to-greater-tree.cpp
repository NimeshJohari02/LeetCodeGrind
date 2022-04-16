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
    // Brute Force -> inorder Trav Store karo . Then for each node it.second se it!= end tak accumulate 
    // Optimised Opproach -> Inorder + Iterate From Back and Store in the  Map
    // Iterative Approach -> Root->val += inOrderSuccessor->val;
    // DFS Approach -> Go right root and left ie Reverse inorder and maintain val sum or maxi to keep tarck
    int sum =0;
    void helper(TreeNode *root){
        if(root == NULL) return ;
        helper(root->right);
        root->val+=sum;
        sum = root->val;
        helper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
      helper(root);
        return root;
    }
};