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

typedef pair<int,bool> myPair;
class Solution {
public:
    
    myPair getFunction(TreeNode *root){
   
   myPair p;
     if(root== NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
    myPair leftPart = getFunction(root->left);
    myPair rightPart = getFunction(root->right);
    p.first= max(leftPart.first,rightPart.first)+1;
    if(abs(leftPart.first-rightPart.first)<=1 and leftPart.second and rightPart.second ){
        p.second = true;
    }
    else{
    p.second = false;
    }
    return p;
    
}
    
    bool isBalanced(TreeNode* root) {
    myPair p = getFunction(root);
    return p.second;
    }
    
};