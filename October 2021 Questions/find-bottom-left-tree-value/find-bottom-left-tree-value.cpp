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
    vector<vector<int>>levelOrder;
    void getLevelOrder(TreeNode *root){
        queue<TreeNode *>q;
        q.push(root);
        vector<int>smallAns;
        while(!q.empty()){
            int k = q.size();  
            for(int j=0;j<k;j++){
                TreeNode * fn = q.front();
                q.pop();
                smallAns.push_back(fn->val);
                if(fn->left){q.push(fn->left);}
                if(fn->right){q.push(fn->right);}
            }
            levelOrder.push_back(smallAns);
            smallAns.clear();
        }
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        getLevelOrder(root);
        return levelOrder.back()[0];
    }
};