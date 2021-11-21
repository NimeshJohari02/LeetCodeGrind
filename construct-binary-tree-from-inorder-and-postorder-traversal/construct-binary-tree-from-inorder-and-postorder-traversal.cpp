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
    unordered_map<int,int>mp;
    TreeNode * helper(vector<int>&in,vector<int>&post,int start, int end){
        if(start>end){
            return NULL;
        }
        int root_value = post.back();
        post.pop_back();
        TreeNode *root = new TreeNode(root_value);
        int idx = mp[root_value];
        root->right=helper(in,post,idx+1,end);
        root->left = helper(in,post,start,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode *root =  helper(in,post,0,in.size()-1);
        return root ;
    }
};