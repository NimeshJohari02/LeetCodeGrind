/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans;
    void helper(TreeNode * orig , TreeNode*cpy , TreeNode*tgt){
        if(orig == NULL) return;
        if(orig->val == tgt->val) {
            ans = cpy;
            return ;
        }
        helper(orig->left , cpy->left , tgt);
        helper(orig->right , cpy->right , tgt);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        helper(original , cloned , target);
        return ans;
    }
};