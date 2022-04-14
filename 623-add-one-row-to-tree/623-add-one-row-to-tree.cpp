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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }   
        int depth = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (depth < d-1) {
            int size = q.size();
            for(int i=0 ; i < size ; i++){
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            depth++;
        }
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            TreeNode *left = curr->left, *right = curr->right;
            curr->left = new TreeNode(v);
            curr->right = new TreeNode(v);
            curr->left->left = left;
            curr->right->right = right;
        }
        return root;
    }
};