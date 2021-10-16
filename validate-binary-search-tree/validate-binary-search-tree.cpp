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
    void trav(TreeNode *root){
        if(root == NULL){
            return ;
        }
        trav(root->left);
        inOrder.push_back(root->val);
        trav(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        trav(root);
        if(inOrder.size()==1){
            return true;
        }
        for(int i=0;i<=inOrder.size()-2;i++){
            if(inOrder[i]>=inOrder[i+1]){
                return false;
            }
        }
        return true;
    }
};