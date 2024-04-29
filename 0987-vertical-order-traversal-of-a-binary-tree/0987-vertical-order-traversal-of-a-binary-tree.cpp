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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>> mp ;
        // vOrder -> levelOrder -> Node
        queue<pair<TreeNode * , pair<int , int>>>q ;
        q.push({root , {0 , 0 }});
        // mp[0][0].insert(root->val);
        while(!q.empty()){
            int size= q.size() ;
                auto top = q.front();
                q.pop();
                auto [node , levelPair] = top;
                int verticalLevel = levelPair.first ;
                int horizontalLevel = levelPair.second ;
                mp[verticalLevel][horizontalLevel].insert(node->val);
                if(node->left)
                    q.push({node->left , {verticalLevel -1 , horizontalLevel +1}});
                if(node->right)
                    q.push({node->right , {verticalLevel +1 , horizontalLevel+1}});
        }   
    //creating resultVector;
        vector<vector<int>>resultVector ;
        for(auto node : mp){
            vector<int>miniAns ;
            for(auto n : node.second){
                miniAns.insert(miniAns.end() , n.second.begin() , n.second.end());
            }
        resultVector.push_back(miniAns);
        }
        return resultVector;
    }
    
};