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
        queue<TreeNode *> q;
        q.push(root);
        vector<int>smallAns;
        while(!q.empty()){
            int k = q.size();
            for(int j=0;j<k;j++){
                TreeNode *frontNode = q.front();
                q.pop();
                smallAns.push_back(frontNode->val);
                if(frontNode->left){q.push(frontNode->left);}
                if(frontNode->right){q.push(frontNode->right);}
            }
            levelOrder.push_back(smallAns);
            smallAns.clear();
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL){
            return {};
        }
        getLevelOrder(root);
        for(auto it : levelOrder){
            ans.push_back(it.back());
        }
        return ans ;
    }
};