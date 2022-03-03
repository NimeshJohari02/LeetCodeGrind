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
typedef unsigned __int128 uint128_t;

class Solution {
    public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,uint128_t>>q;
        q.push({root , 1});
        uint128_t ans=0;
        while(!q.empty()){
            int k = q.size();
            uint128_t l = q.front().second, r = l;
            for(int i=0 ; i < k ; i++){
                TreeNode *node = q.front().first;
                uint128_t curr = q.front().second;
                q.pop();
                r = max(r , curr);
                if(node->left)
                    q.push({node->left , 2*curr});
                if(node->right)
                    q.push({node->right , 2*curr+1});
            }
            ans = max(ans , (r-l+1));
        }
        return ans;
    }
};