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

TreeNode* process(TreeNode *root , TreeNode *end){
    if(root == NULL) return end;
    TreeNode *left = process(root->left , root);
    root ->left = NULL;
    root->right = process(root->right , end);
    return left;
}

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = process(root , NULL);
        return ans;
        
    }
};






