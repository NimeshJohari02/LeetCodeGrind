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
    
    vector<TreeNode*>helper(int start , int end){
        vector<TreeNode*> v;
        if(start > end) {
            v.push_back(NULL);
            return v;
        }
        for(int root = start ; root <= end ; root++){
            auto left = helper(start , root-1);
            auto right = helper(root+1 , end);
            for(auto &l : left)
                for(auto &r : right)
                    v.push_back(new TreeNode(root , l , r));
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        
        return helper(1 , n);
    }
};