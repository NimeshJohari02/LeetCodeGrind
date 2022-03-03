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
    bool helper(TreeNode *root , int targetSum , unordered_set<int>&s){
        if(root==NULL){
            return false;
        }
        if(helper(root->left , targetSum , s)==true){
            return true;
        }
        if(s.find(targetSum - root->val)!= s.end()){
            return true;
        }
        else{
            s.insert(root->val);
        }
        return helper(root->right , targetSum , s );
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        return helper(root , k , s);
    }
};