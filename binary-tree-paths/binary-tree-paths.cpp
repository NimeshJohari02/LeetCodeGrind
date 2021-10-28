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
    vector<string>ans;
    void helper(TreeNode *root , string miniString ){
        if(root == NULL){
            return ;
        }
        if(root->left==NULL and root->right == NULL){
            miniString+=to_string(root->val);
            ans.push_back(miniString);
        }
        miniString+=to_string(root->val)+"->";
        helper(root->left , miniString);
        helper(root->right , miniString);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,"");
        return ans;
    }
};