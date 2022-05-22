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

    // O(nlogn) solution includes that we take inorder and then reorder using sort and then return root of tre e
    // Another Approach is to find 2 Nodes That are in the incorrect position and then swap it .
    // Use Prev to use keep track of the root variable . 
    
class Solution {
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = NULL;
public:
    void recoverTree(TreeNode* root) {
        help(root);
        swap(first->val, second->val);
    }
    
    void help(TreeNode* root){
        if(root==NULL)  return;
        help(root->left);
        if(prev == NULL) prev = root;
        else {
            if(first==NULL && prev->val >= root->val)   first=prev;
            if(first!=NULL && prev->val >= root->val)   second=root;
        }
        prev=root;
        help(root->right);
    }
};