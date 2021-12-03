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
       bool isEvenOddTree(TreeNode* root) {
    bool ans=true;
    int level=0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty() && ans!=false)
    {
        int last;
        if(level%2!=0)last=INT_MAX;
        if(level%2==0)last=INT_MIN;
        int k = q.size();
        for(int j =0 ; j< k ; j++)
        {
            TreeNode* temp=q.front();
            q.pop();  
            if(level%2!=0)
            {
                if(temp->val%2!=0)
                {
                    ans=false;
                    break;
                }
                if(last<=temp->val)
                {
                    ans=false;
                    break;
                }
            }
            if(level%2==0)
            {
                if(temp->val%2==0)
                {
                    ans=false;
                    break;
                }
                if(last>=temp->val)
                {
                    ans=false;
                    break;
                }
            }
            last=temp->val;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        level++;
    }
    return ans;
       }
};