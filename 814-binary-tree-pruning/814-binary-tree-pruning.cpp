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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr ) return nullptr ;
        TreeNode *prunedLeft = pruneTree(root->left);
        TreeNode *prunedRight = pruneTree(root->right);
        root->left = prunedLeft ;
        root->right = prunedRight;
        if(root->val == 1 || root->left != NULL || root->right != NULL) return root ;
        else return nullptr ;
        
    }
};