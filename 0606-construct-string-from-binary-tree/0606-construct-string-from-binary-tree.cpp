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
    string tree2str(TreeNode* root) {
        if(root==nullptr) return "";
        string val = to_string(root->val);
        string leftStr ="", rightStr="";
        if(root->left) 
            leftStr = "("+tree2str(root->left)+")";
        if(!root->left && root->right) leftStr+="()";
        if(root->right)
            rightStr = "("+tree2str(root->right)+")";
        return val+leftStr+rightStr;
    }
};