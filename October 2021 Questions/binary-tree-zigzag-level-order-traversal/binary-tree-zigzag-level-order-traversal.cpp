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
    void rec(TreeNode *root){
        queue<TreeNode *>q;
        stack<int >stk;
        vector<int>miniAns;
        bool rev =false;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            for(int j =0;j<k;j++){
                TreeNode *fp = q.front();
                q.pop();
                if(rev){
                    stk.push(fp->val);
                }
                else{
                    miniAns.push_back(fp->val);
                }
                if(fp->left){q.push(fp->left);}
                if(fp->right){q.push(fp->right);}
            }
            if(!rev){
                ans.push_back(miniAns);
                miniAns.clear();
                rev=true;
            }
            else{
                while(!stk.empty()){
                    miniAns.push_back(stk.top());
                    stk.pop();
                }
                ans.push_back(miniAns);
                rev=!rev;
                miniAns.clear();
            }
        }
        return ;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        rec(root);
        return ans;
    }
};