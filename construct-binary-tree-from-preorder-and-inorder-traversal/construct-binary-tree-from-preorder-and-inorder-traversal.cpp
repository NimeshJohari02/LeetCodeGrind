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
    int preIdx=0;
    TreeNode * helper(vector<int>&pre, vector<int>&in , int i , int j ){
        if(i>j){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[preIdx++]);
        int idx;
        for(int a = i ; a<=j ;a++){
            if(root->val==in[a]){
                idx=a;
                break;
            }
        }
        root->left = helper(pre,in,i,idx-1);
        root->right = helper(pre,in,idx+1,j);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       TreeNode * root = helper(pre , in , 0 ,pre.size()-1 );
        return root;
    }
};