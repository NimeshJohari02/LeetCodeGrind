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
class BSTIterator {
public:
    vector<int>arr;
    void inOrder(TreeNode* root){
        if(root ==NULL){
            return ;
        }
        inOrder(root->right);
        arr.push_back(root->val);
        inOrder(root->left);
        return;
    }
    BSTIterator(TreeNode* root) {
        inOrder(root);
        
    }
    
    int next() {
        int temp = arr.back();
        arr.pop_back();
        return temp;
    }
    
    bool hasNext() {
        return !arr.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */