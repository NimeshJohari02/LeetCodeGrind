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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL and root->right==NULL and root->val==key){
            delete root;
            return NULL;
        }
        if(root->left !=NULL and root->right ==NULL and root->val==key){
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL and root->left == NULL and root->val==key){
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right != NULL and root->left != NULL and root->val==key){
         TreeNode * ngr = root->right;
            while(ngr->left){
                ngr = ngr->left;
            }
            int deleteNum = ngr->val;
            root->val = ngr->val;
            root->right = deleteNode(root->right,deleteNum);
            return root;
        }
        else{
            if(root->val>key){
                root->left = deleteNode(root->left , key);
            }
            else if(root->val<key){
                root->right = deleteNode(root->right,key);
            }
            return root;
        }
    }
};