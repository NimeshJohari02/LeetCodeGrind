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
    priority_queue<string ,vector<string > , greater<string> >q;
    void helper(TreeNode *root , string str){
        if(root->left == NULL && root->right == NULL){
             char ch = root->val + 'a';
        str+=ch;
            reverse(str.begin() , str.end() ) ;
            q.push(str);
            return ;
        }
        char ch = root->val + 'a';
        str+=ch;
        if(root ->left )helper(root->left, str);
        if(root->right) helper(root ->right , str);
        return ;
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL) return "";
        helper(root , "");
        string ans = q.top();
        return ans ;
    }
};