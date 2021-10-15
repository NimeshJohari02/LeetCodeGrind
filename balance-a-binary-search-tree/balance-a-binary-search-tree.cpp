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
    vector<TreeNode *> in;
    void inOrder(TreeNode *root){
        if(root==NULL){
            return ;
        }
        inOrder(root->left);
        in.push_back(root);
        inOrder(root->right);
    }
    TreeNode* CreateBST(int i , int j){
        if(i>j){
            return NULL;
        }
        int mid = (i+j)/2;
        TreeNode *root = new TreeNode(in[mid]->val);
        root->left = CreateBST( i , mid-1);
        root->right = CreateBST(mid+1,j);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        TreeNode *newRoot = CreateBST(0,in.size()-1 );
        return newRoot;
    }
};