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
        if(root==NULL){
            return ;
        }
        trav(root->left);
        inOrder.push_back(root->val);
        trav(root->right);
        return;
    }
    
    int minDiffInBST(TreeNode* root) {
       trav(root);
        int minDif=INT_MAX;

        for(int i=1;i<inOrder.size();i++){
            if((inOrder[i]-inOrder[i-1])<minDif){
                minDif = (inOrder[i]-inOrder[i-1]);
            }
        }
        return minDif; 
    }
};