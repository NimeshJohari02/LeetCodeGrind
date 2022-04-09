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
int distributeCoins(TreeNode* root, TreeNode* parent = NULL) {
  if (root == NULL) return 0;
  int left  = distributeCoins(root->left, root) ;
    int right = distributeCoins(root->right, root);
  if (parent != NULL) parent->val += root->val - 1;
  return (left + right ) + abs(root->val - 1);
}
};