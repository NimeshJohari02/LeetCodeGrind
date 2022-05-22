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
    map<int,vector<int>>mp;
    void helper(TreeNode *root , int height =0){
        if(root == NULL){
            return ;
        }
        mp[height].push_back(root->val);
        helper(root->left , height+1);
        helper(root->right , height+1);
    }
    int deepestLeavesSum(TreeNode* root ) {
        helper(root);
        int ans = 0;
        auto it = mp.rbegin();
        for(auto i : it->second){
            ans +=i;
        }
        return ans;
    }
};