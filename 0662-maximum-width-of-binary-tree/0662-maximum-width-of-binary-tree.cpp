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

// Another Solution is to take the largest int . 
// typedef unsigned __int128 uint128_t;
// then using queue of type queue<pair<TreeNode* , uint128_t>>q ;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long int ans = 0 ;
        queue<pair<TreeNode * , long long int>> q ;
        q.push({root , 1LL});
        while(!q.empty()){
            //since we need values of the level we can use a for loop to keep them sepearate ;
            int queueSize = q.size() , leftIdx , rightIdx;
            int minimizationFactor = q.front().second;
            for(int i=0 ; i < queueSize ; i++){
                auto NodeIndexPair = q.front();
                q.pop();
                auto [node , index]  = NodeIndexPair;
                auto currentIdx = index - minimizationFactor ;
                if(i==0)leftIdx = currentIdx ;
                if(i==queueSize-1)rightIdx = currentIdx;
                if(node->left) q.push({node->left , (2*currentIdx)+1});
                if(node->right)q.push({node->right, (2*currentIdx)+2});
            }
            ans = max(ans , (rightIdx - leftIdx +1)*1LL);
        }
        return ans ; 
    }
};