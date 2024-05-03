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
    void createParentLinks(TreeNode *root , map<TreeNode* , TreeNode*>&mp, int start, TreeNode*& targetNode){
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->val == start) {
                targetNode = node ;
            }
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node ;
                q.push(node->right);
            }
        }
        return ;
    }
    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode* , TreeNode*>mp;
        TreeNode *targetNode = nullptr;
        queue<TreeNode*>q;
        createParentLinks(root , mp , start ,targetNode);
        cout<<targetNode->val ;
        
        
        map<TreeNode* , bool> visited ;

        // Push Target Node in the Queue . 
        q.push(targetNode);
        visited[targetNode] = true ;
        int burnTimer = 0 ;
        while(!q.empty()){
             bool hasBurnt = false;
            int  queueSize = q.size();
            for(int i=0 ; i < queueSize ; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    hasBurnt = true;
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    hasBurnt = true;
                    q.push(node->right);
                    visited[node->right]= true;
                }
                if(mp[node] && !visited[mp[node]]){
                    hasBurnt = true;
                    q.push(mp[node]);
                    visited[mp[node]]= true;
                }
            }
            if(hasBurnt){
                burnTimer++;
            }
        }
        return burnTimer;
    };
};