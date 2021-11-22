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




Alternate Approach From Discuss Section Runtime 32 Seconds
We Know that we have to delete node with key in a bst thus if root->val is > key go left else recursively delete from right half
Then in else we check the 3 standard conditions whether 
1.IsLeaf Node -> delete Directly and return NULL
2.HasOneChild -> Return the only child that would be ok and retain BST property 
3.HasBothChildren -> Replacing The Node by Inorder Successor Or Inorder Predecessor .
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        
        if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(!root->left && !root->right) return NULL; // note !root->left means that left is NULL!!!!
            else if(!root->left && root->right) return root->right;
            else if(!root->right && root->left) return root->left;
            else {
                TreeNode *after = root->left;
                while(after && after->right) {after = after->right;} // InOrder Successor
                after->right = root->right;
                return root->left;
            }
        }
        return root;
    }
};

