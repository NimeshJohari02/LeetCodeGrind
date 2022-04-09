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
class FindElements {
public:
    unordered_map<int,bool>mp;
    void helper(TreeNode *node){
        if(node == NULL) return ;
        int x = node->val;
        if(node->left != NULL) {node->left->val = 2*x+1; mp[2*x+1] = true;}
        if(node->right != NULL){ node->right->val=2*x+2 ; mp[2*x+2] = true;}
        helper(node->left);
        helper(node->right);
    }
    FindElements(TreeNode* root) {
        if(root == NULL) return ;
        root->val =0 ;
        mp[0] = true;
        helper(root);
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */