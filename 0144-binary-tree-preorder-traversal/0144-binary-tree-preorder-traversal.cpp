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
    private :
    vector<int>recursiveTraversal;
    void recursive(TreeNode *root){
        if(root == nullptr) return  ;
        recursiveTraversal.push_back(root->val);
        if(root->left)recursive(root->left);
        if(root->right)recursive(root->right);
        return  ;
    }
    vector<int>iterative(TreeNode* root){
        vector<int>ans ;
        if(root == nullptr) return ans ;
        stack<TreeNode*>stk ;
        stk.push(root);
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            auto leftNode = top->left ;
            auto rightNode = top->right ;
            ans.push_back(top->val);
            if(rightNode)stk.push(rightNode);
            if(leftNode)stk.push(leftNode);
        }
        return ans ;
    }
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        // recursive(root);
        // return recursiveTraversal;
        return iterative(root);
    }
};