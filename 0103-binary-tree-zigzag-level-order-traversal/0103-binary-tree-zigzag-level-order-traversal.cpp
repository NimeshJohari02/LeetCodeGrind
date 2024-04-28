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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        vector<vector<int>>ans ;
        while(!q.empty()){
            int n = q.size();
            vector<int>miniAns(n , 0);
            for(int i=0 ; i < n ; i++){
                auto node = q.front();
                q.pop();
                // miniAns.push_back(node->val);
                int idx = flag ? i : n-i-1;
                miniAns[idx]= node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(miniAns);
            flag = !flag ;
        }
        return ans ; 
    }
};