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
    vector<int>ans;
    void helper(TreeNode *root){
        queue<TreeNode *>q;
        q.push(root);
        int currMax = INT_MIN;
        while(!q.empty()){
            int k = q.size();
            for(int j=0;j<k;j++){
                TreeNode *f = q.front();
                q.pop();
                currMax = max(currMax , f->val);
                if(f->left){q.push(f->left);}
                if(f->right){q.push(f->right);}
            }
            ans.push_back(currMax);
            currMax=INT_MIN;
        }
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        helper(root);
        return ans;
    }
};