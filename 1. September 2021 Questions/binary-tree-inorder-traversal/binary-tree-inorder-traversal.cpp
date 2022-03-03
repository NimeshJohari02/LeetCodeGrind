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
 
    void inorder(TreeNode *root , vector<int>  &v){
        TreeNode *temp = root ; 
        if(temp){
            inorder(temp->left, v ) ;
            v.push_back(temp->val ) ; 
            inorder(temp->right, v ) ; 
            
        }
        return  ; 

        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>  v  ; 
        inorder(root ,v) ; 
        return v ;        
    }
      
};