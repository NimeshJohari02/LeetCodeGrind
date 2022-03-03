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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<pair<TreeNode*, int>> stk; 
        vector<int> pre; 
        vector<int> post; 
        vector<int> in; 

        stk.push({root, 1});
        while(!stk.empty()) {

            TreeNode* node = stk.top().first; 
            int idx = stk.top().second; 

            if(idx==1){
                pre.push_back(node->val);
                stk.top().second += 1; 
                if(node->left) stk.push({node->left, 1});
            }
            else if (idx==2) {
                in.push_back(node->val);
                stk.top().second += 1; 
                if(node->right) stk.push({node->right, 1});
            }
            else{
                post.push_back(node->val); 
                stk.pop();
            }
        }

        return post;
    }
};