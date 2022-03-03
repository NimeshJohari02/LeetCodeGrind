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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<double>ans;
        queue<TreeNode *>q;
        double miniSum =0.0;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                TreeNode *fp= q.front();
                q.pop();
                miniSum += fp->val;
                if(fp->left){q.push(fp->left);}
                if(fp->right){q.push(fp->right);}
            }
            ans.push_back(miniSum / k);
            miniSum =0.0;
        }
        return ans;
    }
};