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
    int ans =0 ;
//     void helper(TreeNode *root , TreeNode *gc ){
//     if(root == NULL){
//         return ;
//     }
//     if(root->val %2 ==0 and gc!=NULL){
//             // cout<<root->val<<" Child Val "<< (gc==NULL?0:gc->val) <<endl;
//             ans += gc->val;
    
//     }
//         if(root->left != NULL and root->right != NULL){
//      helper(root->left , root->left->left);
//      helper(root->left , root->left->right);
//      helper(root->right , root->right->left);
//      helper(root->right , root->right->right);
//         }
//         return ;
//     }
    void specialTrav(TreeNode *curr , TreeNode *parent , TreeNode *gp ){
        if (curr == NULL){
            return ;
        }
        if(gp!= NULL and gp->val %2 ==0){
            ans += curr->val;
        }
        specialTrav(curr->left , curr , parent);
        specialTrav(curr->right , curr , parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        specialTrav(root, NULL , NULL );
        return ans;
    }
};