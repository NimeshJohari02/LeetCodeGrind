/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode *root , unordered_map<TreeNode * , TreeNode *> &mp, TreeNode *target){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
            
        }
        
    }
 vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp; // node -> parent
        markParents(root, mp, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) {
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(mp[current] && !visited[mp[current]]) {
                    queue.push(mp[current]);
                    visited[mp[current]] = true;
                }
            }
        }
        vector<int> ans;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};