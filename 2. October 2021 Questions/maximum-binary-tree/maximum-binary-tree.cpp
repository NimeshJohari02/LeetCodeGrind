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
    TreeNode* helper(vector<int>&nums, int i , int j){
        if(i>j){
            return NULL;
        }
        int currMax = INT_MIN;
        int idx =INT_MIN;
        for(int x = i ; x <= j ; x++){
            currMax= max(currMax,nums[x]);
            if(currMax == nums[x]){
                idx = x; 
            }
        }
        TreeNode* root = new TreeNode(currMax);
        root->left = helper(nums,i , idx-1);
        root->right = helper(nums,idx+1,j);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};