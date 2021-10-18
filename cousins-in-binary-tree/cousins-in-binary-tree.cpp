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
typedef pair<TreeNode *,TreeNode *> np;
//NODE,NODE.Parent ;
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<np> q;
        vector<np>miniAns;
        q.push({root , root});
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                np frontNode = q.front();
                q.pop();
                if(frontNode.first->val == x || frontNode.first->val == y){
                    miniAns.push_back(frontNode);
                }
                if(frontNode.first->left){
                    q.push({frontNode.first->left,frontNode.first});
                }
                
                if(frontNode.first->right){
                    q.push({frontNode.first->right,frontNode.first});
                }
            }
            if(miniAns.size()==1){
                return false;
            }
            else{
                if(miniAns.size()==2){
                    np one = miniAns[0];
                    np two = miniAns[1];
                    if(one.second->val == two.second->val){
                        return false;
                    }
                    else{
                        return true;
                    }
                }
            }
            miniAns.clear();
        }
        return false;
    }
};