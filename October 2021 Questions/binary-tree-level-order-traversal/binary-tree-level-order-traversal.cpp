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
    void Trav(TreeNode *root){
        if(root==NULL){
            return;
        }
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        vector<int>miniAns;
        while(q.size()>1){
            TreeNode *fn = q.front();
            q.pop();
            if(fn == NULL ){
                ans.push_back(miniAns);
                miniAns.clear();
                 q.push(NULL);
                continue;
            }
            miniAns.push_back(fn->val);
            if(fn->left){q.push(fn->left);}
            if(fn->right){q.push(fn->right);}
        }
        ans.push_back(miniAns);
        return ; 
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       Trav(root);
        return ans ;
    }
};