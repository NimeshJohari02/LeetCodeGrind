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
vector<TreeNode*> ans;
    unordered_map<string, int> mp;
    
    string fun(TreeNode* root){
        if(root == NULL){
            return "";
        }
        string a = fun(root -> left);
        string b = fun(root -> right);
        string temp = to_string(root -> val) + "L" + a + "R" + b;
        mp[temp]++;
        if(mp[temp] == 2){
            ans.push_back(root);
        }
        return temp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string t = fun(root);
        return ans;
    }
};