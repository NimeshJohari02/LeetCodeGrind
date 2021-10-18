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
    /*bool isCousins(TreeNode* root, int x, int y) {
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
    }*/
    //This approach from the discuss section is very simple 
    // create helper which recursively . instead of using vertical lines as distance from the root we can use horizontal lines too .
        bool isCousins(TreeNode* root, int x, int y) {
		unordered_map<int, pair<int, int>> m;
		helper(root, 0, -1, m);
		return m[x].first == m[y].first && m[x].second != m[y].second;
    }
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& m) {
    	if (!node) return;
    	m[node->val] = {depth, parent};
    	helper(node->left, depth + 1, node->val, m);
    	helper(node->right, depth + 1, node->val, m);
    }
};