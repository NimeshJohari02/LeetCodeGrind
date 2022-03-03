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
        vector<int>miniAns;
        vector<vector<int>>ans;
    void helper(TreeNode *root , int val){
        if(root == NULL){
            return ;
        }
        miniAns.push_back(root->val);
        if(root->left == NULL and root->right == NULL and root->val==val){
            ans.push_back(miniAns);
        }
        helper(root->left , val-root->val);
        helper(root->right , val-root->val);
        //Backtracking Step so as to account all solutions 
        miniAns.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root , targetSum);
        return ans;
    }
};