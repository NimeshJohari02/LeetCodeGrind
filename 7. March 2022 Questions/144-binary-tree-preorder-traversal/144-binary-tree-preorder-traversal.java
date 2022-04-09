/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
            ArrayList<Integer> arr = new ArrayList<>();
    public void rec(TreeNode root){
        if(root == null) return ;
        arr.add(root.val);
        rec(root.left);
        rec(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        rec(root);
        return arr;
    }
}