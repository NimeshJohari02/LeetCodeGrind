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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        int local_sum=0;
        int ansIdx =0;
        int global_Idx=0;
        int global_sum=INT_MIN;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            for(int j = 0;j<k;j++){
                TreeNode * fn = q.front();
                q.pop();
                local_sum+=fn->val;
                if(fn->left){q.push(fn->left);}
                if(fn->right){q.push(fn->right);}
        }
            ansIdx++;
            // global_sum = max(global_sum,local_sum);
            if(local_sum>global_sum){
                global_sum=local_sum;
                global_Idx=ansIdx;
                
            }
            local_sum=0;
    }
    return global_Idx;
    }
};