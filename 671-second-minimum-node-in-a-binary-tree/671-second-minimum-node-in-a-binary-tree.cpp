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
    int helper(TreeNode* node, int first) {
        if (node== NULL) return -1;
        if (node->val != first) return node->val;
        int left = helper(node->left, first);
        int right = helper(node->right, first);
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int ans = helper(root, root->val);
        return ans;
    }
    
};