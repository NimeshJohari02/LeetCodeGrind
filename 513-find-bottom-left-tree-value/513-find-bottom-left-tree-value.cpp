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
    int findBottomLeftValue(TreeNode* root) {
        
    vector<vector<int>>ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int>miniAns;
            for(int i=0 ; i < k ; i++){
                TreeNode *f = q.front();
                miniAns.push_back(f->val);
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ans.push_back(miniAns);
        }
        return ans.back()[0];
    }
};