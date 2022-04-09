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
    int goodNodes(TreeNode* root , int maxm = INT_MIN) {
       return root!=NULL ? goodNodes(root->left , max(maxm , root->val)) + goodNodes(root->right , max(maxm , root->val)) +(root->val >=maxm) : 0 ; 
    }
};