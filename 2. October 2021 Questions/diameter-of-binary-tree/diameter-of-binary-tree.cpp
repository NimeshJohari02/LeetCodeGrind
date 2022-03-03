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
typedef pair<int,int> htdtPair;
class Solution {
    public:
    htdtPair func(TreeNode *root){
    htdtPair p ;
    if(root == NULL){
    p.first =0;
    p.second =0;
    return p;
    }
    htdtPair l=func(root->left);
    htdtPair r=func(root->right);
    p.first=max(l.first,r.first)+1;
    p.second = max(l.first+r.first,max(l.second,r.second));
    return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        htdtPair ans = func(root);
        return ans.second;
    }
};