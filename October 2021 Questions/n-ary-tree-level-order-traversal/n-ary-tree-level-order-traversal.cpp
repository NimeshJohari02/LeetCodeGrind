/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>ans;
    void helper(Node *root){
        queue<Node *>q;
        vector<int>miniAns ;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            for(int j=0;j<k;j++){
                Node *fn = q.front();
                q.pop();
                miniAns.push_back(fn->val);
                for(auto it : fn->children){
                    if(it){
                        q.push(it);
                    }
                }      
                }
            
            ans.push_back(miniAns);
            miniAns.clear();
        }
    return ;
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        helper(root);
        return ans;
    }
};