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
    TreeNode* helper(TreeNode* root) {
        if (root==NULL)
            return NULL;
        
        TreeNode* leftAns = helper(root->left);
        TreeNode* rightAns = helper(root->right);
        
        
        if (root->left !=NULL && root->right !=NULL) {
            leftAns->right = root->right;
            root->right = root->left;
            // Root Left Should Always be NULL
            root->left = NULL;
            return rightAns;
        } 
        
        else if (root->left != NULL) {
            root->right = root->left;
            root->left = NULL;
            return leftAns;
        }
        else if (root->right != NULL) {
            return rightAns;
        } 
        
        
       return root;
    }
    void flatten(TreeNode* root) {
       root = helper(root) ;
    }
};