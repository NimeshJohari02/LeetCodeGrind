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
    int ans =0;
    void solve(TreeNode *root, int midAns){
        midAns = midAns*10+root->val;
        if(root->left == NULL and root->right == NULL){
            ans +=midAns ;
        }
        if(root->left != NULL){
            solve(root->left , midAns);
        }
        if(root->right != NULL){
            solve(root->right , midAns);
        }
        return;
    }
        int sumNumbers(TreeNode* root) {
        solve(root,0);
            return ans ;
    }

};