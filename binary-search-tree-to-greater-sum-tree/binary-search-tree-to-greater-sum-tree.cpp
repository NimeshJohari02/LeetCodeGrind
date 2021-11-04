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
    vector<int>inOrder;
    void trav(TreeNode *root ){
        if(root == NULL){
            return ;
        }
        trav(root->left);
        inOrder.push_back(root->val);
        trav(root->right);
        return;
    }
    void reconstruct(TreeNode *root){
        if(root == NULL){
            return ;
        }
        reconstruct(root->right);
        root->val = inOrder.back();
        inOrder.pop_back();
        reconstruct(root->left);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        trav(root);
        for(int i= inOrder.size()-2;i>=0;i--){
            inOrder[i]+=inOrder[i+1];
        }
        for(auto it : inOrder){
            cout<<it<<"  ";
        }
        reconstruct(root);
        return root;
    }
    
};