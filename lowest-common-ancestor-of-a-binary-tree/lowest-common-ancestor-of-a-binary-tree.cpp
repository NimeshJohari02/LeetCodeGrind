/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> path1;
    vector<TreeNode *> path2;
    bool findPath(TreeNode *root , TreeNode *target,vector<TreeNode *>&path){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root->val == target->val ){
            return true;
        }
        if(findPath(root->left,target,path) || findPath(root->right,target,path)){
            return true;
        }
        //BackTrack if path was not found 
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool p1 = findPath(root , p , path1);
        bool p2 = findPath(root , q , path2);
        if(!p1 || !p2 ){
            return NULL;
        }
        cout<<p1<<p2<<endl;
        for(auto it : path1){
            cout<<it->val<<"    ";
        }
        cout<<endl;
          for(auto it : path2){
            cout<<it->val<<"    ";
        }
        cout<<endl;
        int i =0;
        while(i<path1.size() and i <path2.size() and path1[i]->val==path2[i]->val){
            i++;
        }
        return path1[i-1];
    }
};