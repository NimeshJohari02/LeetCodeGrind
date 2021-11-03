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
    map<int,int>mp;
    int preIdx = 0;
    TreeNode* constructTree(vector<int>&pre,vector<int>&in, int st, int end){
        if(st>end){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[preIdx++]);
        int idx = mp[root->val];
        root->left = constructTree(pre,in,st,idx-1);
        root->right = constructTree(pre,in,idx+1,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in(pre);
      
        sort(in.begin(),in.end());
          for(auto it : in){
            cout<<it<<endl;
        }
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        TreeNode *root = constructTree(pre , in , 0 , in.size()-1);
        return root ;  
    }
};