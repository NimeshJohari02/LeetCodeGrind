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
    int solve(TreeNode *root , int &res){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left , res);
        int right = solve(root->right , res);
        int tempAns = max(root->val , max(left ,right)+root->val);
        int ans = max(tempAns , left + right + root->val);
        res = max(res , ans);
        return tempAns;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = INT_MIN;
        int  dummy = solve(root , res);
        return res;
    }
};