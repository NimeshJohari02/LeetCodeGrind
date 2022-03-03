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
    vector<vector<int>>ans;
    void func(TreeNode *root){
        vector<int>miniAns;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int k= q.size();
            for(int j=0;j<k;j++){
                TreeNode *fp = q.front();
                q.pop();
                miniAns.push_back(fp->val);
                if(fp->left){
                    q.push(fp->left);
                }
                if(fp->right){
                    q.push(fp->right);
                }
            }
            ans.push_back(miniAns);
            miniAns.clear();
        }
        return ;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        func(root);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};